#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE *pFile = NULL;
	FILE *pWriteFile = NULL;

	pFile = fopen("./PeopleOnStreet_1280x720_30_Original.yuv", "rb");    
	pWriteFile = fopen("./result/YUV_Y_0.yuv", "wb"); 
	

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
        // fseek(pWriteFile, (long)resolution_size / 2, SEEK_CUR);// A.번의 경우 포인터를 넘어가기 위함  
		fseek(pFile, (long)frame_size / 2, SEEK_CUR);




        
    }
    fclose(pFile);
	fclose(pWriteFile);
	printf("finish\n");
	return 0;

}