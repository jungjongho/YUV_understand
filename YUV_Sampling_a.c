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
	pWriteFile = fopen("./result/YUV_Y_sampling_a1.yuv", "wb"); 

	time_t start = time(NULL);

	if(pFile == NULL) {
        printf("file is not exist\n");
        return 0;
	}

    int frame_size = 1280 * 720 * 1 ; 
	unsigned char* frame = (unsigned char*)malloc(frame_size/2); 


    for (int i = 0; i < 30; i++) {
        
        memset(frame, 0, frame_size/2);
        for (int j = 0; j<frame_size/2; j++)
        {
            fread(frame, sizeof(unsigned char), 1, pFile);
            fwrite(frame, sizeof(unsigned char), 1, pWriteFile);
            fseek(pFile, 1, SEEK_CUR);
        }

        fseek(pFile, frame_size * 1/2, SEEK_CUR);

    }

    fclose(pFile);
	fclose(pWriteFile);


    pFile2 = fopen("./result/YUV_Y_sampling_a1.yuv", "rb");    
	pWriteFile2 = fopen("./result/YUV_Y_sampling_a2.yuv", "wb");

    if(pFile2 == NULL) {
        printf("file is not exist\n");
        return 0;
	}

    int frame_size2 = 640 * 720 * 1 ; 
	unsigned char* frame2 = (unsigned char*)malloc(frame_size2); 


    for (int i = 0; i < 30; i++) {
        

        for (int j = 0; j<frame_size2/1280; j++)
        {
            memset(frame2, 0, 640);
            fread(frame2, sizeof(unsigned char), 640, pFile2);
            fwrite(frame2, sizeof(unsigned char), 640, pWriteFile2);
            fseek(pFile2, 640, SEEK_CUR);

        }



    }

    fclose(pFile2);
	fclose(pWriteFile2);

    time_t end = time(NULL);


    


	printf("finish\n");
    printf("a 방법 소요시간: %lf\n", (double)(end - start));
	return 0;

}