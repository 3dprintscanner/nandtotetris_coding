// what does assembler code look like???? 
// A calls start with a 0
// Register /  Compute  calls start with a 1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct 
{
	char * name;

} symbol;

enum command_type
{
	A_COMMAND,
	C_COMMAND,
	L_COMMAND
};


typedef struct
{
	char * line;
	enum command_type command_type; 
	char * address_register;
} command;





int get_symbol(command * command, char * symbol)
{
	if (command->command_type == C_COMMAND) return -1;
}

symbol * init_symbols()
{
	symbol * sym[3];

	symbol *firstSymbol =  (symbol*)malloc(sizeof(symbol));
	firstSymbol->name = "loop";
	symbol *secondSymbol = (symbol*)malloc(sizeof(symbol));
	secondSymbol->name = "end";
	symbol *thirdSymbol = (symbol*)malloc(sizeof(symbol));
	thirdSymbol->name = "third";

	sym[0] = firstSymbol;
	sym[1] = secondSymbol;
	sym[2] = thirdSymbol;

	return sym;
}

char* get_val_string(command * instructions)
{
	
}


void add_areg_instr(char* line, command * instructions)
{
	switch (instructions->command_type)
	{
	case A_COMMAND:
		{
			// actual number to set the numerical register
			// get the actual chars from the 
		instructions->address_register = get_val_string(instructions);

		}break;
	case C_COMMAND: break;
	case L_COMMAND:
		{
			
			// symbol to resolve
		} break;
	default: ;
	}
	

};

void add_compute_instr(char* line, command * instructions)
{
	
};

bool is_symbolic_command(char * line)
{
	// what do we know about the number defined??? is the first char a numerical char??
	int result = atoi(&line[0]);

	if (result == 0) return true;
}

void parseline(char * line, command * command)
{
	// is this an A register move??? 


	if(line[0] == '@')
	{
		// check if its a symbolic command or its a number
		if(is_symbolic_command(line))
		{
			command->command_type = L_COMMAND;
		}else
		{
			command->command_type = A_COMMAND;
		}
		add_areg_instr(line, command);
	}else
	{
		add_compute_instr(line, command);
	}

}


int main(char * args[])
{
	
	symbol * baseSymbols = init_symbols();

	// read each line of the file and parse it depending on whether the initial bit it set to 0 or 1
	
	FILE *fstream;
	

	int err =  fopen_s(&fstream, args[1], "r");
	if (err != 0)
	{
		printf("cannot open file %s - return code %d", args[1], err);
		return 1;
	}
	
	const size_t line_size = 64;
	char * line = malloc(line_size * sizeof(char));
	
	while(fgets(line,line_size,fstream) != NULL)
	{
		command command;
		printf(line);
		parseline(line, &command);
	}

}











