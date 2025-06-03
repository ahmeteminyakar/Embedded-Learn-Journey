#include <stdio.h>




int main(){


    int regs[4] = {0x00000000, 0xAABBCCDD, 0x12345678, 0xFFFFFFFF};
    int* reg_ptr = regs;

    for (int i = 0; i < 4 ; i++){

        printf("------------regs[%d]------------\n",i);
        printf("Value : 0x%x at adress :%p Delta from regs[0] = %ld bytes\n" , *(reg_ptr+i), (void*)(reg_ptr+i) , (char*)(reg_ptr +i)- (char*)(reg_ptr));

        


    }
    

    char* byte_view = (char*)&regs[2];
    byte_view[1] = 0x99;

    printf("regs[2] value = 0x%x \n" , regs[2]);


    int final = 0xBEEFCAFE;

    int* ptr1 = &final;
    int** pptr1 = &ptr1;



    printf("Address of final: %p\n", (void*)&final);
    printf("Value in ptr:    0x%x\n", *ptr1);
    printf("Value in *pptr:   %p\n", (void*)*pptr1);

     
    return 0;
}