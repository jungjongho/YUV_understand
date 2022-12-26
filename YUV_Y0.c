#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE *pFile = NULL;
	FILE *pWriteFile = NULL;

	pFile = fopen("./PeopleOnStreet_1280x720_30_Original.yuv", "rb");    
	pWriteFile = fopen("./result/YUV_Y_128.yuv", "wb"); 
	

	if(pFile == NULL) {
        printf("file is not exist\n");
        return 0;
	}

    int frame_size = 1280 * 720 * 1 ; 
	unsigned char* frame = (unsigned char*)malloc(frame_size); 


    for (int i = 0; i < 30; i++) {
        
        
        memset(frame, 0, frame_size);
        fread(frame, sizeof(unsigned char), frame_size, pFile);
        fwrite(frame, sizeof(unsigned char), frame_size, pWriteFile);
        
        memset(frame, 0, frame_size);
        fwrite(frame, sizeof(unsigned char), frame_size * 1/2, pWriteFile); 
        fread(frame, sizeof(unsigned char), frame_size * 1/2, pFile); 



        
    }
    fclose(pFile);
	fclose(pWriteFile);
	printf("finish\n");
	return 0;

}