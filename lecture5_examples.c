void f(int *a) //same as int a[]
{
  a[0] = 7;
}

int main()
{
    int a[] = {5, 6, 7};
    a[0] = 6;
    int *p = a;
    f(a);
    printf("%d\n", a[0]); // 7


    int arr[] = {4,5,6};
    sizeof(arr); // 12
    //total num of memeory cells occupied by arr ~ num of elements in the array
    //sizeof(arr)/sizeof(arr[0]) gives you num of elements in array

    int *p_a0 = arr;
    //sizeof(p_a0) NOT THE SUM OF ELEMENTS IN THE ARRAY * 4
    //num of memeory cells occupied by an address since p_a0

    //p_a0[0] is the same as p_a0[0] bc is the same as *(p_a0 + 0)
    }