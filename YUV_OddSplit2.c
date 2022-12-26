#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// 1. 입출력을 위해 파일 열기  
	FILE *pFile = NULL;
	FILE *pWriteFile = NULL;
	pFile = fopen("./PeopleOnStreet_1280x720_30_Original.yuv", "rb");    
	pWriteFile = fopen("./result/YUV_Y_0.yuv", "wb"); 
	
	// 2. 파일 존재 여부 확인  
	if(pFile == NULL) {
		fputs("Read File doesnt exist", stderr);
		exit(1);
		
	}
	
	// 3. 해상도 사이즈만큼 프레임의 크기를 설정한다.  
	int resolution_size = 1280 * 720 *(1+0.25+0.25); // 해상도 크기(Y + U + V의 크기) 
	unsigned char* frame = (unsigned char*)malloc(resolution_size); // 동적 할당  
	
	// 4. 프레임들을 순회하면서, 홀수번째 pic만 저장  
	for (int frame_num = 0; frame_num < 30; frame_num++) {
		if(frame_num % 2 == 0) { // 4.1 버퍼크기만큼 초기화 후 한 프레임 읽은 후 그대로 저장하고자 하는 파일에 쓴다.
			memset(frame, 0, resolution_size);
			fread(frame, sizeof(unsigned char), resolution_size, pFile);
			fwrite(frame, sizeof(unsigned char), resolution_size, pWriteFile);
		} else {// 4.2읽기만 한다.  
			fread(frame, sizeof(unsigned char), resolution_size, pFile);
			memset(frame, 0, resolution_size);
		}
	}
	
	// 5. 파일 닫기 및 제거  
	// delete frame;
	fclose(pFile);
	fclose(pWriteFile);
	printf("end");
	return 0;
}