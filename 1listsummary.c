#include <stdio.h>
// 插入元素函数 O(n)
void insertElement(int arr[], int *n, int index, int element) {
    // 检查插入位置是否合法
    if (index < 0 || index > *n) {
        printf("插入位置不合法\n");
        return;
    }
    // TODO 移动元素，从最后一个元素开始往后移
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
    // TODO 移动元素，从删除位置开始往前移
    for(int i = index;i<*n-1;++i){
        arr[i]=arr[i+1];
    }
    // TODO 返回新的数组大小
    *n = *n - 1; //(*n)--;
}

int main() {
    int num[5] = {10, 20, 30, 40, 50};
    int size = sizeof(num) / sizeof(num[0]);
    // TODO 插入新元素 25 到索引 2 的位置
    insertElement(num,&size,2,25);
    // 输出插入后的数组
    printf("数组插入后: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    // TODO 删除索引 3 处的元素，同时更新数组大小
    deleteElement(num,&size,3);
    // 输出删除后的数组
    printf("\n数组删除后: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    return 0;
}
