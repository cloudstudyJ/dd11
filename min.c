#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point Point;

void printPoints(FILE* fp) 
{
    Point pt;
    rewind(fp); // 파일 포인터를 처음으로 이동
    for (int i = 0; i < 10; i++) 
    {
        fread(&pt, sizeof(Point), 1, fp);
        printf("Point %d: (%d, %d)\n", i, pt.x, pt.y);
    }
}

void modifyPoint(FILE* fp, int index) 
{
    Point pt;
    printf("수정할 Point의 좌표 입력: ");
    scanf("%d %d", &pt.x, &pt.y);

    // 파일 포인터를 수정할 위치로 이동
    fseek(fp, index * sizeof(Point), SEEK_SET);
    fwrite(&pt, sizeof(Point), 1, fp);
}

int main(void)
{
    // 바이너리 모드로 10개의 Point 값(x, y)을 파일로 저장한다.
    srand(time(NULL));
    FILE* fp = fopen("point.txt", "wb");
    for (int i = 0; i < 10; i++)
    {
        Point pt = { rand() % 10, rand() % 10 };
        fwrite(&pt, sizeof(Point), 1, fp);
    }
    fclose(fp);

    // point.txt 파일을 읽고쓰기/바이너리모드로 연다. 읽기모드가 기본이다. "rb+"
    fp = fopen("point.txt", "rb+");
    if (fp == NULL) 
    {
        perror("파일 열기 실패");
        return EXIT_FAILURE;
    }

    // 메뉴에 따라 수행하기를 반복 수행한다.
    int choice;
    while (1)
    {
        printf("\n메뉴:\n1. 포인트 수정\n2. 포인트 출력\n0. 종료\n선택: ");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            int index;
            printf("수정할 Point의 index를 입력하세요: ");
            scanf("%d", &index);
            if (index < 0 || index >= 10) 
            {
                printf("잘못된 인덱스입니다. 0에서 9 사이의 값을 입력하세요.\n");
            }
            else
            {
                modifyPoint(fp, index);
            }
        }

        else if (choice == 2)
        {
            printPoints(fp);
        }

        else if (choice == 0) 
        {
            break;
        }
        
    }

    // 파일을 닫는다.
    fclose(fp);
    return 0;
}
