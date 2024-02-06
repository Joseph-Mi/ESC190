// Solution for Q_1
int a = 42;

// Solution for Q_2
int *pa = &a;

// Solution for Q_3
*pa = 43;

// Solution for Q_4
int b = 90;
pa = &b;
  
  // Solution for Q_5
void change_int(int *point){
  *point = 80;
}

int main(){
  // Solution for Q_6
  change_int(&a);
  
  // Solution for Q_7
  change_int(pa);
  printf("%d", a);

  // Solution for Q_12
  change_ppint(&pa);
  change_ppint(ppa);

  // Solution for Q_13
  change_pointer(&pa);

  // Solution for Q_14
  change_pointer(ppa);

  // Solution for Q_13
  int[] = {5,6,7};
}
// Solution for Q_8
int **ppa;

// Solution for Q_9
ppa = *pa;

// Solution for Q_10
void change_ppint(int **p){
  **p = 46;
}
// Solution for Q_11
void change_pointer(int **p){
  *p = (int *)malloc(sizeof(int));
}

// Solution for Q_16
void change_arr(int *arr){
  *(arr+2) = 8;
}

// Solution for Q_17

// Solution for Q_18

// Solution for Q_19

// Solution for Q_20

// Solution for Q_21

// Solution for Q_22

// Solution for Q_23

// Solution for Q_24

// Solution for Q_25

// Solution for Q_26

// Solution for Q_27

// Solution for Q_28

// Solution for Q_29

// Solution for Q_30

// Solution for Q_31

// Solution for Q_32
