#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE *pFile = NULL;
	FILE *pWriteFile = NULL;

	pFile = fopen("./ParkScene_1920x1080_24.yuv", "rb");    
	pWriteFile = fopen("./result/ParkScene_1920x1080_24_90.yuv", "wb"); 
	

	if(pFile == NULL) {
        printf("file is not exist\n");
        return 0;
	}

    // int frame_size = 1280 * 720 * 1 ;
    int frame_size = 1920 * 1080 * 1 ; 
	unsigned char* frame = (unsigned char*)malloc(frame_size); 


    for (int i = 0; i < 90; i++) {
        
        
        memset(frame, 0, frame_size);

        fread(frame, sizeof(unsigned char), frame_size, pFile);
        fwrite(frame, sizeof(unsigned char), frame_size, pWriteFile);


        memset(frame, 0, frame_size);
        fread(frame, sizeof(unsigned char), frame_size/2, pFile);
        fwrite(frame, sizeof(unsigned char), frame_size/2, pWriteFile);

        
    }
    fclose(pFile);
	fclose(pWriteFile);
	printf("finish\n");
	return 0;

}