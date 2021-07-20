#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

    uint32_t file[3], add_total;
    FILE *data=0;
    for(int i=1; i <3; i++){
        data=fopen(argv[i],"rb");
        fread(&file[i],sizeof(file),1,data);
    }

            if(data==NULL){
                printf("NULL FILE error!!!");
                return -1;
            }
               file[1] = ntohl(file[1]); // first file data
               file[2] = ntohl(file[2]); // second file data
               add_total = file[1]+file[2] ;
               printf("%d(0x%x)+%d(0x%x)= %d(0x%x)",file[1], file[1], file[2],file[2], add_total, add_total);

    fclose(data);
    return 0;
}
