/* bitset.cpp */

#include <iostream>

class Bitset
{
public:
	Bitset (const int);
	~Bitset();
	Bitset & set (); 
	Bitset & set (const int); 
	Bitset & reset ();
	Bitset & reset (const int);
	Bitset & flip ();
	void init_arr ();
	void print_arr ();
private:
	unsigned int * m_arr;
	unsigned int m_arr_size;
 	const static int ibit = 8 * sizeof (unsigned int);
};

Bitset::Bitset (const int num) : m_arr_size {1}
{
	if (num <= ibit) 
	{ 
		m_arr = new unsigned int[m_arr_size]; 
		m_arr [0]= 0;
	}
	else
	{
		m_arr_size = num / ibit;
		if (num % ibit == 0)
		{	
			m_arr = new unsigned int[m_arr_size];
			init_arr ();	
		}
		else
		{
			m_arr = new unsigned int[++m_arr_size];
			init_arr ();
		}
	}
}   

void Bitset::init_arr ()
{
	for (int i{}; i<m_arr_size; ++i)
	{
		m_arr[i] = 0;
	}
}

Bitset & Bitset::set ()
{
	for (int i{}; i<m_arr_size; ++i)
	{
		m_arr[i] = 0;
		m_arr[i] = ~ m_arr[i];
	}
	print_arr ();
	std::cout<< std::endl;
	return *this;
}

Bitset & Bitset::set (const int num)
{	
	if (num >= (m_arr_size * ibit) or num < 0)
	{
		std::cout<< "It's not a safe to refer that place, it isn't array's place. (set func) \n";
		return *this;
	}
	int revers_transfer = ibit * m_arr_size - num - 1;
	int arr_index { revers_transfer / ibit};
	int bit_index { revers_transfer % ibit };
	unsigned int one {1};
	one <<= bit_index;
	m_arr[m_arr_size - arr_index -1] |= one;
	print_arr ();
	std::cout<< std::endl;
	return *this;
}

Bitset & Bitset::reset ()
{
	for (int i{}; i<m_arr_size; ++i)
	{
		m_arr[i] = 0;
	}
	print_arr ();
	std::cout<< std::endl;
	return *this;
}

Bitset & Bitset::reset (const int num)
{	
	if (num >= (m_arr_size * ibit) or num < 0)
	{
		std::cout<< "It's not a safe to applay that place, it isn't array's place. (reset func) \n";
		return *this;
	}
	int revers_transfer = ibit * m_arr_size - num - 1;
	int arr_index { revers_transfer / ibit};
	int bit_index { revers_transfer % ibit};
	unsigned int one {1};
	one <<= bit_index;
	one = (~one);
	m_arr[m_arr_size - arr_index -1] &= one;
	print_arr ();
	std::cout<< std::endl;
	return *this;
}

Bitset & Bitset::flip ()
{
	for (int i{}; i<m_arr_size; ++i)
	{
		m_arr[i] = (~m_arr[i]);
	}
	print_arr ();
	std::cout<< std::endl;
	return *this;
}

Bitset::~Bitset() 
{
	delete [] m_arr;
	m_arr = nullptr;
}

void Bitset::print_arr ()
{
	for (int i{}; i<m_arr_size; ++i)
	{
		 std::cout<< m_arr[i] << "\t";
	}
}

int main ()
{
	Bitset ob (187);	
	ob.set ();
	ob.reset ();
	ob.set (19);
	ob.set (120);
	ob.reset (19);
	ob.reset (120);

return 0;
}
