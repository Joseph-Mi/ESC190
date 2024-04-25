int array_len(int *arr){
    int count = 0;
    while (arr[count]){
        count++;
    }
    return count;
}

int str_len(char *str){
    int count = 0;
    while(*(str+count)){
        count++;
    }
    return count;
}



int main(){
    int array[] = {1,2,4,6};
    int len = array_len(array);
    printf("%d", len);

    char *word = "hello";
    int len2 = str_len(word);
    printf("%d", len2);
}

