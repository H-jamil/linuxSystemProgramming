/**
 * @Author: jamil
 * @Date:   2021-02-26T22:32:19-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-02-26T23:14:31-06:00
 */



# 1 "test.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 366 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "test.c" 2







# 1 "./test.h" 1
# 9 "test.c" 2




double
compute_square(int x){
  return (x*x);
}

double
compute_circle_area(int radius){
  return 3.14*compute_square(radius);
}

int
main(int argc, char **argv){
  int radius=10;
  compute_circle_area(radius);
  compute_circle_area(100);
  return 0;
}
