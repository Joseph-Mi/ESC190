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
  change_int_ptr(&pa);

  // Solution for Q_14
  change_int_ptr(ppa);

  // Solution for Q_15
  int arr[] = {5,6,7};

  // Solution for Q_17
  change_arr(arr);

  // Solution for Q_18
  int p_block[] = (int *)malloc(sizeof(int) * 3);
  change_arr(p_block); 

  // Solution for Q_19
  change_int(p_block);

  //Solution for Q_20
  change_int_ptr(&p_block);

  // Solution for Q_21
  student s = {"Allan", 18, "University of Toronto"};

  // Solution for Q_22
  strcpy(s.name, "Jennifer");

  // Solution for Q_23
  s.age = 21;

  // Solution for Q_24
  student *p_s = &s;

  // Solution for Q_25
  strcpy(p_s->name, "Jenny");

  // Solution for Q_26
  p_s->age = 20;

  // Solution for Q_29
  change_name(p_s);

  // Solution for Q_30
  change_age(&s);

  // Solution for Q_31
  student arr[5];

  // Solution for Q_32
  change_name(arr[2]);
  change_age(arr[2]);
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
void change_int_ptr(int **p){
  *p = (int *)malloc(sizeof(int));
}

// Solution for Q_16
void change_arr(int *arr){
  *(arr+2) = 8;
}

// Solution for Q_21
typedef struct student{
  char name[500];
  int age;
  char school[2000];
} student;

// Solution for Q_27
void change_name(student *s){
  strcpy(s->name, "Jenny");
}

// Solution for Q_28
void change_age(student *s){
  s->age = 20;
}



// Solution for Q_30

// Solution for Q_31

// Solution for Q_32
