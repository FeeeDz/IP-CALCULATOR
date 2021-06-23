#include "utils.h" //inclusion of the "utils.h" library in which the functions used are contained
#include <stdio.h>

void menu()
{
    banner(0);
    printf("© Credits Authors ©\nhttps://github.com/FeeeDz\nhttps://github.com/Th3F0x-code");
    printf("\n\n1 --> Check if two IPs belong to the same network\n");
    printf("2 --> Subnetting calculation\n");
    printf("3 --> VLSM calculation\n");
    printf("4 --> Clean the file\n");
    printf("5 --> Exit\n");
}

int main()
{
    //variables declaration
    int ip1[3], ip2[3], ip3[3], ip4[3], cidr;
    int mod;
    int nhost, nsubnet;
    address sub;
    int numvlsm, vlsm[20], host[20], somma;
    mem_init();                //buffer initialization
    fp = fopen("ip.txt", "w"); //cleaning file at the beginning to avoid finding data related to other executions
    fclose(fp);
    do
    {
        menu();
        printf("--> ");
        scanf("%d", &mod);
        printf("\n\n");
        switch (mod)
        {
        case 1: //Check if two IPs belong to the same network
            do
            {
                printf("Enter the IP --> ");
            } while (input(&ip1[0], &ip2[0], &ip3[0], &ip4[0], 0));

            do
            {
                printf("Enter the second ip --> ");
            } while (input(&ip1[1], &ip2[1], &ip3[1], &ip4[1], 0));

            do
            {
                printf("Enter the subnet mask --> ");
            } while (input(&ip1[2], &ip2[2], &ip3[2], &ip4[2], 1));

            printf("First IP --> ");
            bin(&sub, ip1[0], ip2[0], ip3[0], ip4[0], 1);
            printf("Class --> %c\n", classe(ip1[0]));
            printf("Second IP --> ");
            bin(&sub, ip1[1], ip2[1], ip3[1], ip4[1], 1);
            printf("Class --> %c\n", classe(ip1[1]));
            printf("Subnet IP --> ");
            bin(&sub, ip1[2], ip2[2], ip3[2], ip4[2], 1);

            if ((classe(ip1[0])) != (classe(ip1[1])))
            {
                printf("The two IPs do not belong to the same network\n");
            }
            else if (check_network(ip1, ip2, ip3, ip4))
            {
                printf("The two IPs belong to the same network\n");
            }
            else
            {
                printf("The two Ip's do NOT belong to the same subnet.\n");
            }
            break;
        case 2: //Subnetting calculation
            banner(2);
            do
            {
                printf("Enter the IP --> ");
            } while (input(&ip1[0], &ip2[0], &ip3[0], &ip4[0], 0));
            do
            {
                printf("Enter the subnet in CIDR format --> ");
            } while (check_cidr(&cidr) != 0);
            calc(&nsubnet, &nhost, bit_host(cidr, ip1[0]), bitsubnetting(cidr, ip1[0]));
            int nreti;
            printf("Enter the number of nets you want to print --> ");
            scanf("%d", &nreti);
            //stampa dei risultati richiesti dalla consegna
            printf("IP --> %d.%d.%d.%d --> Class %c\n", ip1[0], ip2[0], ip3[0], ip4[0], classe(ip1[0]));
            printf("IP binary format --> ");
            bin(&sub, ip1[0], ip2[0], ip3[0], ip4[0], 1);
            printf("Block --> %d\n", blocco(bitsubnetting(cidr, ip1[0])));
            printf("Bit subnetting --> %d\n", bitsubnetting(cidr, ip1[0]));
            printf("Bit host --> %d\n", bit_host(cidr, ip1[0]));
            printf("Numbers subnet --> %d\n", nsubnet);
            printf("Numbers of hosts --> %d\n\n", nhost);
            nsubnet = nreti;
            print_ip(ip1[0], ip2[0], ip3[0], ip4[0], blocco(bitsubnetting(cidr, ip1[0])), nsubnet);
            break;
        case 3: //VLSM calculation
            banner(1);
            printf("Enter the IP --> ");
            input(&ip1[0], &ip2[0], &ip3[0], &ip4[0], 0);
            printf("Enter number of subnets --> ");
            scanf("%d", &numvlsm);
            for (int i = 0; i < numvlsm; i++)
            {
                printf("Enter number of PCs for the network %d --> ", i + 1);
                scanf("%d", &vlsm[i]);
            }
            printf("\n");
            for (int i = 0; i < numvlsm; i++)
            {
                printf("Network number %d has %d host\n", i + 1, vlsm[i]);
            }
            printf("\nIP binary format --> ");
            bin(&sub, ip1[0], ip2[0], ip3[0], ip4[0], 1);
            printf("\n\n");
            printf("Hosts in descending order : \n");
            shakersort(vlsm, numvlsm);
            for (int i = 0; i < numvlsm; i++)
            {
                printf("%d\n", vlsm[i]);
            }
            printf("\n\n");
            numhost(numvlsm, host, vlsm, &somma);
            id_sub(classe(ip1[0]), numvlsm, host, somma, ip3[0], ip4[0], ip2[0], ip1[0]);
            break;
        case 4: //file cleaning
            cleanfile();
            break;

        case 5: //program exit
            return 0;
        default: //default case
            printf("Inserisci una della opzioni indicate sopra\n");
        }
    } while (1);
}