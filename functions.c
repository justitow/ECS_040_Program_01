void addl(int* op1, int* op2){

	*op2 = *op1 + *op2;




}

void andl(int *op1, int *op2){

	
	*op2 = *op1 & *op2;


}

void leave(Register *register, int *memory){

	register->regs[esp] = register->regs[ebp];
	register->regs[esp] = memory[register->regs[ebp]]+4;

}


void movl(int *op1, int *op2){

	*op2 = *op1


}



void pushl(int *op1, int *memory, Register *register){

	register->regs[esp] -= 4;
	memory[register->regs[esp]] = *op1; 


}


void ret(Register *register, int *memory){

	memory[register->regs[eip]] = memory[register->regs[esp]];
	register->regs[esp] += 4;

}


void subl(int *op1, int *op2){


	*op2 = *op1 - *op2;


}