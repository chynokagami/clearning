#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PLAYER_COUNT 50

// 插入元素函数 O(n)
void insertElement(int arr[], int *n, int index, int element) {
    // 检查插入位置是否合法
    if (index < 0 || index > *n) {
        printf("插入位置不合法\n");
        return;
    }
    // 移动元素，从最后一个元素开始往后移
    for(int i=*n-1;i>index;--i){
        arr[i]=arr[i-1];
    }
    // TODO 在插入位置插入新元素
    arr[index]=element;
}

// 删除元素函数，返回新的数组大小 O(n)
void deleteElement(int arr[], int *n, int index) {
    // 检查删除位置是否合法
    if (index < 0 || index >= *n) {
        printf("删除位置不合法\n");
    }
    //  移动元素，从删除位置开始往前移
    for(int i = index;i<*n-1;++i){
        arr[i]=arr[i+1];
    }
    //  返回新的数组大小
    *n = *n - 1; //(*n)--;
}

void SwapElements(int array[], int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void ShuffleArray(int array[], int length) {
    srand(time(NULL));
    //[0, RAND_MAX]
    for (int i = length - 1; i > 0; --i) {
        int random_number = rand() % i;
        SwapElements(array, i, random_number);
    }
}

int main() {
    int num[5] = {10, 20, 30, 40, 50};
    int size = sizeof(num) / sizeof(num[0]);
    //  插入新元素 25 到索引 2 的位置
    insertElement(num,&size,2,25);
    // 输出插入后的数组
    printf("数组插入后: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    //  删除索引 3 处的元素，同时更新数组大小
    deleteElement(num,&size,3);
    // 输出删除后的数组
    printf("\n数组删除后: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    puts("");

    int players[PLAYER_COUNT];
    for (int i = 0; i < 50; ++i) {
        players[i] = i;
    }
    // players : 0, 1, ..., 49
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        printf("Player[%d]: %d ", players[i],i);
    }
    puts(" ");
    ShuffleArray(players, PLAYER_COUNT);
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        printf("Player[%d]: %d ", players[i],i);
    }
    return 0;
}
