
#include<string>

using namespace std ;

////////////////////////////////////////////////////////
//    1. Globol Constance Data
////////////////////////////////////////////////////////

const int  MAX_CHAR_OF_LINE = 100   ;
const int  MAX_LINE_OF_FILE = 100   ;


////////////////////////////////////////////////////////
//    2. Globol Data
////////////////////////////////////////////////////////

unsigned long int START_ADDRESS         ;
unsigned long int PROGRAM_LENGH         ;
unsigned long int LOC[MAX_LINE_OF_FILE] ;
unsigned long int BASE                  ;
bool USE_SICXE							;
bool haveLoc[MAX_LINE_OF_FILE]			;
string PROGRAM_NAME						;
string OBJCodeALL[MAX_LINE_OF_FILE]		;
string OBJPROG[MAX_LINE_OF_FILE]		;
int objprog_length						;

////////////////////////////////////////////////////////
//    3. Instruction Set Data
////////////////////////////////////////////////////////

const int MAX_SICXE_IS = 59  ;

class SICXE_IS
{
public:
	SICXE_IS( string m_M             ,
		      string m_F             ,
		      unsigned long int m_Op ,
			  string m_N)
			 : Mnemonic(m_M),Format(m_F),Opcode(m_Op),Note(m_N)  {}

	string Mnemonic          ;
	string Format            ;
	unsigned long int Opcode ;
	string Note		         ;
} ISA[MAX_SICXE_IS] = 
	{	
	    SICXE_IS( "ADD"   , "34" , 0x18 , ""    ) ,
		SICXE_IS( "ADDF"  , "34" , 0x58 , "XF"  ) ,
		SICXE_IS( "ADDR"  , "2"  , 0x90 , "X"   ) ,
		SICXE_IS( "AND"   , "34" , 0x40 , ""    ) ,
		SICXE_IS( "CLEAR" , "2"  , 0xB4 , "X"   ) ,
		SICXE_IS( "COMP"  , "34" , 0x28 , "C"   ) ,
		SICXE_IS( "COMPF" , "34" , 0x88 , "XFC" ) ,
		SICXE_IS( "COMPR" , "2"  , 0xA0 , "XC"  ) ,
		SICXE_IS( "DIV"   , "34" , 0x24 , ""    ) ,
		SICXE_IS( "DIVF"  , "34" , 0x64 , "XF"  ) ,
		SICXE_IS( "DIVR"  , "2"  , 0x9C , "X"   ) ,
		SICXE_IS( "FIX"   , "1"  , 0xC4 , "XF"  ) ,
		SICXE_IS( "FLOAT" , "1"  , 0xC0 , "XF"  ) ,
		SICXE_IS( "HIO"   , "1"  , 0xF4 , "PX"  ) ,
		SICXE_IS( "J"     , "34" , 0x3C , ""    ) ,
		SICXE_IS( "JEQ"   , "34" , 0x30 , ""    ) ,
		SICXE_IS( "JGT"   , "34" , 0x34 , ""    ) ,
		SICXE_IS( "JLT"   , "34" , 0x38 , ""    ) ,
		SICXE_IS( "JSUB"  , "34" , 0x48 , ""    ) ,
		SICXE_IS( "LDA"   , "34" , 0x00 , ""    ) ,
		SICXE_IS( "LDB"   , "34" , 0x68 , "X"   ) ,
		SICXE_IS( "LDCH"  , "34" , 0x50 , ""    ) ,
		SICXE_IS( "LDF"   , "34" , 0x70 , "XF"  ) ,
		SICXE_IS( "LDL"   , "34" , 0x08 , ""    ) ,
		SICXE_IS( "LDS"   , "34" , 0x6c , "X"   ) ,
		SICXE_IS( "LDT"   , "34" , 0x74 , "X"   ) ,
		SICXE_IS( "LDX"   , "34" , 0x04 , ""    ) ,
		SICXE_IS( "LPS"   , "34" , 0x0D , "PX"  ) ,
		SICXE_IS( "MUL"   , "34" , 0x20 , ""    ) ,
		SICXE_IS( "MULF"  , "34" , 0x60 , "XF"  ) ,
		SICXE_IS( "MULR"  , "2"  , 0x98 , "X"   ) ,
		SICXE_IS( "NORM"  , "1"  , 0xC8 , "XF"  ) ,
		SICXE_IS( "OR"    , "34" , 0x44 , ""    ) ,
		SICXE_IS( "RD"    , "34" , 0xD8 , "P"   ) ,
		SICXE_IS( "RMO"   , "2"  , 0xAC , "X"   ) ,
		SICXE_IS( "RSUB"  , "34" , 0x4C , ""    ) ,
		SICXE_IS( "SHILTF", "2"  , 0xA4 , "X"   ) ,
		SICXE_IS( "SHIFTR", "2"  , 0xA8 , "X"   ) ,
		SICXE_IS( "SIO"   , "1"  , 0xF0 , "PX"  ) ,
		SICXE_IS( "SSK"   , "34" , 0xEC , "PX"  ) ,
		SICXE_IS( "STA"   , "34" , 0x0C , ""    ) ,
		SICXE_IS( "STB"   , "34" , 0x78 , "X"   ) ,
		SICXE_IS( "STCH"  , "34" , 0x54 , ""    ) ,
		SICXE_IS( "STF"   , "34" , 0x80 , "XF"  ) ,
		SICXE_IS( "STI"   , "34" , 0xD4 , "PX"  ) ,
		SICXE_IS( "STL"   , "34" , 0x14 , ""    ) ,
		SICXE_IS( "STS"   , "34" , 0x7C , "X"   ) ,
		SICXE_IS( "STSW"  , "34" , 0xE8 , "P"   ) ,
		SICXE_IS( "STT"   , "34" , 0x84 , "X"   ) ,
		SICXE_IS( "STX"   , "34" , 0x10 , ""    ) ,
		SICXE_IS( "SUB"   , "34" , 0x1C , ""    ) ,
		SICXE_IS( "SUBF"  , "34" , 0x5C , "XF"  ) ,
		SICXE_IS( "SUBR"  , "2"  , 0x94 , "X"   ) ,
		SICXE_IS( "SVC"   , "2"  , 0xB0 , "X"   ) ,
		SICXE_IS( "TD"    , "34" , 0xE0 , "PC"  ) ,
		SICXE_IS( "TIO"   , "1"  , 0xF8 , "PXC" ) ,
		SICXE_IS( "TIX"   , "34" , 0x2C , "C"   ) ,
		SICXE_IS( "TIXR"  , "2"  , 0xB8 , "XC"  ) ,
		SICXE_IS( "WD"    , "34" , 0xDC , "P"   )
	}; 

///////////////////////////////////////////////////////
//    4. Register Data
///////////////////////////////////////////////////////

class SICXE_REGISTER
{
public:
	SICXE_REGISTER(string name)
		: RegName(name) {}
	string RegName ;
	unsigned long int Data ;
} REG[10] = 
		{
			SICXE_REGISTER("A" ) ,  // 0
			SICXE_REGISTER("X" ) ,  // 1
			SICXE_REGISTER("L" ) ,  // 2
			SICXE_REGISTER("B" ) ,  // 3
			SICXE_REGISTER("S" ) ,  // 4
			SICXE_REGISTER("T" ) ,  // 5
			SICXE_REGISTER("F" ) ,  // 6
			SICXE_REGISTER(""  ) ,  // 7
			SICXE_REGISTER("PC") ,  // 8
			SICXE_REGISTER("SW") ,  // 9
		} ;

///////////////////////////////////////////////////////
//    5. Symble Table
///////////////////////////////////////////////////////

const int MAX_SYMTAB = 100 ;

struct SICXE_SYMTAB
{
	string SymName ;
	unsigned long int data ;
} symtab[MAX_SYMTAB] ;

int SYMTAB_LENGTH = 0 ;

///////////////////////////////////////////////////////
//    6. Literal Table
///////////////////////////////////////////////////////

const int MAX_LITERALS = 100 ;

struct SICXE_LITERAL_POOL
{
	string value ;
	unsigned long int address ;
	bool created ;
} literal[MAX_LITERALS] ;

int LITERAL_LENGTH ;


///////////////////////////////////////////////////////
//    Source Code Parsing Functions
///////////////////////////////////////////////////////

void ToUP(string& str)
{
	for(int i=0 ; i<str.length() ; i++)
	{
		if( str[i] >= 'a' && str[i] <= 'z' )
			str[i] = str[i] -'a' + 'A' ;
	}
}

void SourceCodeParse(string str,string& lable,string& op,string& addr)
{
	char *p1,*p2,*p3 ;

	string tmp = string(str.begin(),str.end()) ;

	p1 = strtok((char *)str.data()," \t") ;
	p2    = strtok(NULL," \t") ;
	p3  = strtok(NULL," \t") ;

	if( p3 == NULL )
	{
		lable = "" ;
		if( p2 == NULL )
			addr = "" ;
		else
			addr = p2 ;
		if( p1 == NULL )
			op = "" ;
		else
			op = p1 ;
	}
	else
	{
		lable = p1 ;
		op = p2 ;
		addr = p3 ;
	}
	ToUP(op) ;
	str = tmp ;
}

///////////////////////////////////////////////////////
//    Fill Chars Function
///////////////////////////////////////////////////////

string FillChar(string str,char c,int max,int dir)
{
	while( str.length() < max )
	{
		if( dir == 0 )
			str = c + str ;
		else
			str = str + c ;
	}
	return str ;
}

///////////////////////////////////////////////////////
//    HexChar Functions
///////////////////////////////////////////////////////

int GetHexValue(char c)
{
	if( c>='0' && c<='9')
		return c - '0' ;
	else if( c>='A' && c<='Z' )
		return c - 'A' + 10 ;
	else if( c>='a' && c<='z' )
		return c - 'a' + 10 ;
	else
		return 0 ;
}

char GetHexChar(int c)
{
	c %= 16 ;
	if( c<10 )
		return c + '0' ;
	else
		return c - 10 + 'A' ;
}

///////////////////////////////////////////////////////
//   String/Int Translation
///////////////////////////////////////////////////////

bool HexStringToInt(string str,unsigned long int& loc)
{
	loc = 0 ;

	for( int i=0 ; i<str.length() ; i++)
	{
		if( (str[i] >='0' && str[i] <='9') ||
			(str[i] >='a' && str[i] <='f') ||
			(str[i] >='A' && str[i] <='F') )
			loc = (loc*16) + GetHexValue(str[i]) ;
		else
			return false ;
	}
	return true ;
}

string IntToHexString(unsigned long int v)
{
	string r ;
	do
	{
		r = GetHexChar(v%16)+r ;
		v/=16 ;
	}while( v!=0 ) ;

	return r ;
}

bool DecStringToInt(string str,long int& v)
{
	v = 0 ;
	for( int i=0 ; i<str.length() ; i++)
	{
		if( str[i] >='0' && str[i] <= '9' )
			v = v*10 + str[i] - '0' ;
		else
			return false ;
	}
	return true ;
}

string IntToDecString(unsigned long int v)
{
	string r ;
	do
	{
		r = GetHexChar(v%10)+r ;
		v/=10 ;
	}while( v!=0 ) ;
	return r ;
}

///////////////////////////////////////////////////////
//   SIC/XE Source Code Associations
///////////////////////////////////////////////////////

int GetTotalBytes(string str)
{
	int tmp = 0 ;
	if( str[0] == 'X' )
	{
		tmp = str.length() - 3 ;
		if( tmp%2 == 1)
			tmp = (tmp + 1)/2 ;
		else
			tmp /= 2 ;
		return tmp ;
	}
	else if( str[0] == 'C' )
	{
		return str.length() - 3 ;
	}

	return -1 ;
}

string GetConstString(string str)
{
	string r ;
	long int v ;

	if( str[0] == 'C' )
	{
		str = string(str.begin()+2,str.end()-1) ;
		
		for( int i=0 ; i<str.length() ; i++)
		{
			r = r + IntToHexString(str[i]) ;
		}
	}
	else if( str[0] == 'X' )
	{
		str = string(str.begin()+2,str.end()-1) ;
		r = str ;
	}
	else if( DecStringToInt(str,v) == true )
	{
		r = IntToHexString(v) ;
	}

	return r ;
}

unsigned long int GetNextLOC(int idx)
{
	for( int i=idx+1 ; i<MAX_LINE_OF_FILE ; i++)
	{
		if( haveLoc[i] == true )
			return LOC[i] ;
	}
	return LOC[idx] ;
}

///////////////////////////////////////////////////////
//   SIC/XE Data Insert/Search Assocoations
///////////////////////////////////////////////////////

int SearchFromSymTab(string lab)
{
	for( int i=0 ; i<SYMTAB_LENGTH ; i++)
	{
		if( symtab[i].SymName == lab )
			return i ;
	}
	return -1 ;
}

int SearchFromReg(string reg)
{
	for( int i=0 ; i<10 ; i++)
	{
		if(REG[i].RegName == reg )
			return i ;
	}
	return -1 ;
}

int SearchFromLiteral(string l)
{
	for( int i=0 ; i<LITERAL_LENGTH ; i++)
	{
		if( literal[i].value == l )
			return i ;
	}
	return -1 ;
}

bool InsertToSymTab(string lab,unsigned long int loc)
{
	if(SYMTAB_LENGTH >= MAX_SYMTAB)
		return false ;

	symtab[SYMTAB_LENGTH].SymName = lab ;
	symtab[SYMTAB_LENGTH].data    = loc ;
	SYMTAB_LENGTH++ ;

	return true ;
}

int SearchFromISA(string op)
{
	for( int i=0 ; i<MAX_SICXE_IS ; i++)
	{
		if( ISA[i].Mnemonic == op )
			return i ;
	}
	return -1 ;
}

///////////////////////////////////////////////////////
//    Pass1
///////////////////////////////////////////////////////

bool SICXEPass1(string* sStr,int TotalLines , string& msg)
{
	string lable , op , addr ;
	unsigned long int LOCCTR ;
	bool UseFormat4 ;

	int i = 0 ;

	while( sStr[i].length() ==0 ) i++ ;

	SourceCodeParse(sStr[i],lable,op,addr) ;

	if( op == "START" )
	{
		PROGRAM_NAME = lable ;
		if( HexStringToInt(addr,LOCCTR) == false )
		{
			msg = "Start Address error!!\n" ;
			return false ;
		}
		SourceCodeParse(sStr[++i],lable,op,addr) ;
	}
	else
	{
		LOCCTR = 0x0 ;
	}

	START_ADDRESS = LOCCTR ;
	LOC[0] = START_ADDRESS ;
	haveLoc[0] = true ;

	while( op != "END" && i<TotalLines )
	{
		UseFormat4 = false ;

		if( op[0]!='.' && lable[0]!='.' && addr[0]!='.' && op != "" && 
			op != "BASE")  // if not a comment
		{
			LOC[i] = LOCCTR ;
			haveLoc[i] = true ;

			if( lable.length()>0 )
			{
				if( SearchFromSymTab(lable) >=0 )
				{
					msg = "redefine LABLE " + lable ;
					return false ;
				}
				else
				{
					InsertToSymTab(lable,LOCCTR) ;
				}
			}

			if( op[0] == '+' || addr[0] == '@' || addr[0] == '#' )
			{
				if(op[0] == '+')
				{
					UseFormat4 = true ;
					op = string(op.begin()+1,op.end()) ;
				}
				USE_SICXE  = true ;
			}

			if(addr[0] == '=' && SearchFromLiteral(string(addr.begin()+1,addr.end()))<0 )
			{
				USE_SICXE = true ;
				literal[LITERAL_LENGTH].value = addr ;
				literal[LITERAL_LENGTH].created = false ;
				LITERAL_LENGTH++ ;
			}

			int j = SearchFromISA(op) ;

			if( j>=0 )
			{
				if( ISA[j].Format == "1" )
					LOCCTR += 1 ;
				else if( ISA[j].Format == "2" )
					LOCCTR += 2 ;
				else
				{
					if(UseFormat4==true)
						LOCCTR += 4 ;
					else
						LOCCTR += 3 ;
				}

				if( ISA[j].Note.find("X") != string::npos )
					USE_SICXE = true ;
			
			}
			else if( op == "WORD" )
			{
				LOCCTR += 3 ;
			}
			else if( op == "RESW" )
			{
				long int tmp ;
				if( DecStringToInt(addr,tmp)==false )
				{
					msg = addr + " is not a integer!" ;
					return false ;
				}
				else
					LOCCTR +=  3*tmp ;
			}
			else if( op == "RESB" )
			{
				long int tmp ;
				if( DecStringToInt(addr,tmp)==false )
				{
					msg = addr + " is not a integer!" ;
					return false ;
				}
				else
					LOCCTR += tmp ;
			}
			else if( op == "BYTE" )
			{
				if( GetTotalBytes(addr)<0)
				{
					msg = addr + " is not a current value!" ;
					return false ;
				}
				LOCCTR += GetTotalBytes(addr) ;
			}
			else if( op == "LTORG" )
			{
				for( int i=0 ; i<LITERAL_LENGTH ; i++)
				{
					if( !literal[i].created )
					{
						literal[i].address = LOCCTR ;
						LOCCTR += GetTotalBytes(literal[i].value) ;
						literal[i].created = true ;
					}
				}
			}
			else if( op == "EQU" )
			{

			}
			else if( op == "ORG" )
			{

			}	
			else if( op == "USE" )
			{

			}
			else
			{
				msg = "Error Instruction " + op ;
				return false ;
			}
		}
		SourceCodeParse(sStr[++i],lable,op,addr) ;
	}

	for( int j=0 ; j<LITERAL_LENGTH ; j++)
	{
		if( !literal[j].created )
		{
			literal[j].address = LOCCTR ;
			LOCCTR += GetTotalBytes(literal[j].value) ;
			literal[j].created = true ;
		}
	}

	PROGRAM_LENGH = LOCCTR - START_ADDRESS ;

	return true ;
}

////////////////////////////////////////////////////////
//   Pass2
////////////////////////////////////////////////////////

bool SICXEPass2(string* sStr,int TotalLines , string& msg)
{
	string lable , op , addr ;

	int i = 0 ;

	if( TotalLines!=0 )
		SourceCodeParse(sStr[0],lable,op,addr) ;

	if( op == "START" )
	{
		if( i<TotalLines )
			SourceCodeParse(sStr[++i],lable,op,addr) ;
	}

	while( op != "END" && i<TotalLines )
	{
		if( USE_SICXE )
		{
			bool UseFormat4 = false ;

			if( op[0] == '+' )
			{
				USE_SICXE = true ;
				UseFormat4 = true ;
				op = string(op.begin()+1,op.end()) ;
			}

			int findfromisa = SearchFromISA(op) ;

			if(findfromisa>=0)
			{
				string tmp_op,tmp_operand ;

				tmp_op = IntToHexString(ISA[findfromisa].Opcode) ;

				if(ISA[findfromisa].Format == "1" )
				{
					OBJCodeALL[i] = tmp_op ;
				}
				else if(ISA[findfromisa].Format == "2" )
				{
					int k ;
					k = SearchFromReg( string(addr.begin(),addr.begin()+1));
					if( k<0 )
					{
						msg = "register error! on " + sStr[i] ;
						return false ;
					}
					tmp_operand = IntToDecString(k) ;
					if( addr.length() >=3 )
					{
						k = SearchFromReg( string(addr.begin()+2,addr.begin()+3));
						if( k<0 )
						{
							tmp_operand += addr[2] ;
						}
						else
						{
							tmp_operand += IntToDecString(k) ;
						}
					}
					else
					{
						tmp_operand += "0" ;
					}
					OBJCodeALL[i] = tmp_op + tmp_operand ;
				}
				else // fotmat 3 4
				{
					int flag = 0x32 ;

					if( addr[0] == '#' )
					{
						flag &= 0x1F ;
						addr = string( addr.begin()+1, addr.end()) ;
					}
					if( addr[0] == '@' )
					{
						flag &= 0x2F ;
						addr = string( addr.begin()+1, addr.end()) ;
					}
					if( addr.find(",X") != string::npos )
					{
						flag &= 0x08 ;
						addr = string( addr.begin() , addr.end()-2 ) ;
					}

					int j = SearchFromSymTab(addr) ;
					
					int k = SearchFromLiteral(addr) ;
						
					if( j>=0 )
					{
						int disp ;
	
						if( UseFormat4 )
						{
							disp = symtab[j].data ;
						}
						else
						{
							disp = symtab[j].data - GetNextLOC(i) ;

							if( disp>2047 || disp < -2048 )	
							{
								disp = symtab[j].data - BASE ;
		
								if( disp > 4095 || disp < 0)
								{
									msg = "BASE Relation error!" ;
									return false ;				
								}
	
								flag &= 61 ; 
								flag |= 4 ;
							}
							else if( disp < 0 )
							{
								disp &= 0x00000FFF ;
							}
						}
						tmp_operand = IntToHexString(disp) ;
					}
					else if( k>=0 )
					{
						int disp ;
	
						if( UseFormat4 )
						{
							disp = literal[k].address ;
						}
						else
						{
							disp = literal[k].address - GetNextLOC(i) ;

							if( disp>2047 || disp < -2048 )	
							{
								disp = literal[k].address - BASE ;
		
								if( disp > 4095 || disp < 0)
								{
									msg = "BASE Register error!2" ;
									return false ;				
								}
	
								flag &= 61 ; 
								flag |= 4 ;
							}
							else if( disp < 0 )
							{
								disp &= 0x00000FFF ;
							}
						}
						tmp_operand = IntToHexString(disp) ;
					}
					else
					{
						long int v ;
						flag &= 57 ;
						if( !DecStringToInt(addr,v) )
						{
							msg = "operand error" ;
							return false ;
						}
						tmp_operand = IntToHexString(v) ;
					}
					
					if( UseFormat4 )
					{
						tmp_operand = FillChar(tmp_operand,'0',5,0) ;
						flag &= 57 ;
						flag |= 1  ;
					}
					else
					{
						tmp_operand = FillChar(tmp_operand,'0',3,0) ;
					}
					
					tmp_operand = IntToHexString(flag) + tmp_operand ;
					unsigned long int a,b ;
					HexStringToInt(tmp_op,a) ;
					HexStringToInt(tmp_operand,b) ;
					
					if( UseFormat4 )
					{
						a <<= 24 ;
						OBJCodeALL[i] = FillChar(IntToHexString(a+b),'0',8,0) ;
					}
					else
					{
						a <<= 16 ;
						OBJCodeALL[i] = FillChar(IntToHexString(a+b),'0',6,0) ;
					}
				}	
			}
			else if( op == "WORD" )
			{
				long int v ;
				DecStringToInt(addr,v) ;
				OBJCodeALL[i] = FillChar(IntToHexString(v),'0',6,0) ;
			}
			else if( op == "BYTE" )
			{
				OBJCodeALL[i] = GetConstString(addr) ;
			}
			else if( op == "BASE" )
			{
				int j = SearchFromSymTab(addr) ;
				BASE = symtab[j].data ;
			}
			else
			{
			
			}
		}
		else
		{
			int findfromisa = SearchFromISA(op) ;
			
			if( findfromisa >= 0 )
			{
				string tmp_op , tmp_operand ;

				tmp_op = FillChar(IntToHexString(ISA[findfromisa].Opcode),'0',2,0) ;

				bool indexed = false ;

				if( addr.find(",X") != string::npos )
				{
					indexed = true ;
					addr = string( addr.begin() , addr.end()-2 ) ;
				}

				int k = SearchFromSymTab(addr) ;

				if(k>=0)
				{
					long int a = symtab[k].data ;
					if( indexed )
						a &= 0x8000 ;
					tmp_operand = FillChar(IntToHexString(a),'0',4,0) ;
				}
				else
				{
					tmp_operand = "0000" ;
				}
				OBJCodeALL[i] = tmp_op + tmp_operand ;
			}
			else if( op == "WORD" )
			{
				long int v ;
				DecStringToInt(addr,v) ;
				OBJCodeALL[i] = FillChar(IntToHexString(v),'0',6,0) ;
			}
			else if( op == "BYTE" )
			{
				OBJCodeALL[i] = GetConstString(addr) ;
			}
		}

		if( i<TotalLines-1)
			SourceCodeParse(sStr[++i],lable,op,addr) ;
	}

	return true ;
}

///////////////////////////////////////////////////////
//   Create Object Program
///////////////////////////////////////////////////////

void CreateSICXEObjectProgram(int TotalLines)
{
	objprog_length = 0 ;

	OBJPROG[objprog_length++] = "H" + FillChar(PROGRAM_NAME,' ',6,1)
		                      + FillChar(IntToHexString(START_ADDRESS),'0',6,0)
							  + FillChar(IntToHexString(PROGRAM_LENGH),'0',6,0);

	int tmp_length = 0 ;
	int tmp_start  = -1 ;
	bool flag = true ;
	string tmp_str = "" ;

	for( int i=0 ; i<TotalLines ; i++)
	{
		if( flag )
		{
			tmp_start = LOC[i] ;
		}

		if( OBJCodeALL[i].length() != 0 )
		{
			flag = false ;
			if( tmp_length + OBJCodeALL[i].length() <=60 )
			{
				tmp_str += OBJCodeALL[i] ;
				tmp_length += OBJCodeALL[i].length() ;
			}
			else
			{
				OBJPROG[objprog_length++] = "T" +
					                        FillChar(IntToHexString(tmp_start),'0',6,0) +
											FillChar(IntToHexString(tmp_length/2),'0',2,0) +
											tmp_str ;
				tmp_str = OBJCodeALL[i] ;
				tmp_start = LOC[i] ;
				tmp_length = OBJCodeALL[i].length() ;
			}
		}
		else
		{
			if( haveLoc[i] )
			{
				flag = true ;
				if( tmp_str != "" )
				{
					OBJPROG[objprog_length++] = "T" +
					                        FillChar(IntToHexString(tmp_start),'0',6,0) +
											FillChar(IntToHexString(tmp_length/2),'0',2,0) +
											tmp_str ;
					tmp_str = "" ;
					tmp_length = 0 ;
				}
			}
		}
	}
	
	OBJPROG[objprog_length++] = "T" +
							FillChar(IntToHexString(tmp_start),'0',6,0) +
							FillChar(IntToHexString(tmp_length/2),'0',2,0) +
							tmp_str ;
	OBJPROG[objprog_length++] = "E" + 
							FillChar(IntToHexString(START_ADDRESS),'0',6,0) ;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
