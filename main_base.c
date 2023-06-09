#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    long long 바코드;
    char 상품명[50];
    char 분류[50];
    int 가격;
    char 제조사[50];
    int 재고량;
    char 유통기한[11];
    struct Item *next;
} Item;

Item *head = NULL;

Item *create_item(long long 바코드, char *상품명, char *분류, int 가격, char *제조사, int 재고량, char *유통기한)
{
    Item *new_item = (Item *)malloc(sizeof(Item));
    new_item->바코드 = 바코드;
    strcpy(new_item->상품명, 상품명);
    strcpy(new_item->분류, 분류);
    new_item->가격 = 가격;
    strcpy(new_item->제조사, 제조사);
    new_item->재고량 = 재고량;
    strcpy(new_item->유통기한, 유통기한);
    new_item->next = NULL;
    return new_item;
}

void add_item(long long 바코드, char *상품명, char *분류, int 가격, char *제조사, int 재고량, char *유통기한)
{
    Item *new_item = create_item(바코드, 상품명, 분류, 가격, 제조사, 재고량, 유통기한);
    if (head == NULL)
    {
        head = new_item;
    }
    else
    {
        Item *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_item;
    }
}

void display_items()
{
    Item *temp = head;
    if (temp == NULL)
    {
        printf("인벤토리가 비어 있습니다.\n");
        return;
    }
    printf("인벤토리에 있는 상품:\n");
    while (temp != NULL)
    {
        printf("바코드: %lld, 상품명: %s, 분류: %s, 가격: %d, 제조사: %s, 재고량: %d, 유통기한: %s\n",
               temp->바코드, temp->상품명, temp->분류, temp->가격, temp->제조사, temp->재고량, temp->유통기한);
        temp = temp->next;
    }
}

Item *search_item(long long 바코드)
{
    Item *temp = head;
    while (temp != NULL)
    {
        if (temp->바코드 == 바코드)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void delete_item(long long 바코드)
{
    Item *temp = head;
    Item *prev = NULL;

    if (temp != NULL && temp->바코드 == 바코드)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->바코드 != 바코드)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("상품을 찾을 수 없습니다.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    int 선택;
    long long 바코드;
    int 재고량;
    char 상품명[50], 분류[50], 제조사[50], 유통기한[11];
    int 가격;
    while (1)
    {
        printf("\n인벤토리 관리 시스템\n");
        printf("1. 상품 추가\n");
        printf("2. 상품 목록 표시\n");
        printf("3. 상품 검색\n");
        printf("4. 상품 삭제\n");
        printf("5. 종료\n");
        printf("선택하세요: ");
        scanf("%d", &선택);

        switch (선택)
        {
        case 1:
            printf("상품 바코드 입력: ");
            scanf("%lld", &바코드);
            printf("상품명 입력: ");
            scanf(" %[^\n]%*c", 상품명);
            printf("분류 입력: ");
            scanf(" %[^\n]%*c", 분류);
            printf("가격 입력: ");
            scanf("%d", &가격);
            printf("제조사 입력: ");
            scanf(" %[^\n]%*c", 제조사);
            printf("재고량 입력: ");
            scanf("%d", &재고량);
            printf("유통기한 입력 (YYYY-MM-DD): ");
            scanf(" %10s", 유통기한);
            add_item(바코드, 상품명, 분류, 가격, 제조사, 재고량, 유통기한);
            break;
        case 2:
            display_items();
            break;
        case 3:
            printf("상품 바코드 입력: ");
            scanf("%lld", &바코드);
            Item *item = search_item(바코드);
            if (item)
            {
                printf("바코드: %lld, 상품명: %s, 분류: %s, 가격: %d, 제조사: %s, 재고량: %d, 유통기한: %s\n",
                       item->바코드, item->상품명, item->분류, item->가격, item->제조사, item->재고량, item->유통기한);
            }
            else
            {
                printf("상품을 찾을 수 없습니다.\n");
            }
            break;
        case 4:
            printf("상품 바코드 입력: ");
            scanf("%lld", &바코드);
            delete_item(바코드);
            break;
        case 5:
            printf("종료 중...\n");
            exit(0);
            break;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}