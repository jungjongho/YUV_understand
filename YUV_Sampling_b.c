#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    FILE *pFile = NULL;
	FILE *pWriteFile = NULL;

    FILE *pFile2 = NULL;
	FILE *pWriteFile2 = NULL;

	pFile = fopen("./PeopleOnStreet_1280x720_30_Original.yuv", "rb");    
	pWriteFile = fopen("./result/YUV_Y_sampling_b1.yuv", "wb"); 

	time_t start = time(NULL);

	if(pFile == NULL) {
        printf("file is not exist\n");
        return 0;
	}

    int frame_size = 1280 * 720 * 1 ; 
	unsigned char* frame = (unsigned char*)malloc(frame_size/2); 

    for (int i = 0; i < 30; i++) {
        
        memset(frame, 0, frame_size/2);
        for (int j = 0; j<frame_size/(1280*2); j++)
        {
            memset(frame, 0, 1280);
            fread(frame, sizeof(unsigned char), 1280, pFile);
            fwrite(frame, sizeof(unsigned char), 1280, pWriteFile);
            fseek(pFile, 1280, SEEK_CUR);

        }

        fseek(pFile,frame_size * 1/2 , SEEK_CUR);

    }
    
    fclose(pFile);
	fclose(pWriteFile);


    pFile2 = fopen("./result/YUV_Y_sampling_b1.yuv", "rb");    
	pWriteFile2 = fopen("./result/YUV_Y_sampling_b2.yuv", "wb");

    if(pFile2 == NULL) {
        printf("file is not exist\n");
        return 0;
	}

    int frame_size2 = 1280 * 360 * 1 ; 
	unsigned char* frame2 = (unsigned char*)malloc(frame_size2/2); 


    for (int i = 0; i < 30; i++) {
        
        memset(frame2, 0, frame_size2/2);
        for (int j = 0; j<frame_size2/2; j++)
        {

            fread(frame2, sizeof(unsigned char), 1, pFile2);
            fwrite(frame2, sizeof(unsigned char), 1, pWriteFile2);
            fseek(pFile2, 1, SEEK_CUR);

        }



    }

    time_t end = time(NULL);





	printf("finish\n");
    printf("b 방법 소요시간: %lf\n", (double)(end - start));
	return 0;

}