/*
Given an api which returns an array of chemical names and an array of chemical symbols,
display the chemical names with their symbol surrounded by square brackets

EX:
chemical array: ['Amazon', 'Microsoft', 'Google']
Symbols: ['I', 'Am', 'cro', 'Na', 'le', 'abc']

return
[Am]azon, Mi[cro]soft, Goog[le]

If the chemical string matches more than one symbol, then choose the
one with longest length. (ex: 'Microsoft' matches 'i' and 'cro')
 */

public static void replace() {
		String[] symbols = { "I", "Am", "cro", "Na", "le", "abc" };
		String[] arr = { "Amazon", "Microsoft", "Google" };
		for (int i = 0; i < arr.length; i++) {
			String name = arr[i];
			String selectedSymbol = "";
			for (String symbol : symbols) {
				if (name.contains(symbol)) {
					if (symbol.length() > selectedSymbol.length())
						selectedSymbol = symbol;
				}
			}
			if (selectedSymbol.length() > 0) {
				arr[i] = name.replace(selectedSymbol, "[" + selectedSymbol + "]");
			}
		}
		System.out.println(Arrays.toString(arr));
	}

#include <string>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool sort_by_length(const string &str1, const string &str2)
{
   return str1.length() >= str2.length();
}

void sort_vector_by_len(vector<string> &vec)
{
   sort(vec.begin(), vec.end(), sort_by_length);
}

void display_new_string(const string &str1, const string &str2)
{
   string nStr;

   int start = str1.find(str2), end = start + str2.length();

   for(int i = 0; i < str1.length(); i++)
   {
      if(start == i)
      {
         nStr += "[";
      }

      nStr += str1[i];

      if(end == i + 1)
      {
         nStr += "]";
      }
   }

   printf("NEW STRING: %s\n", nStr.c_str());
}

int main(int argc, char** argv)
{
   vector<string> names, symbols;

   names.push_back("Amazon");
   names.push_back("Microsoft");
   names.push_back("Google");

   symbols.push_back("I");
   symbols.push_back("Am");
   symbols.push_back("cro");
   symbols.push_back("Na");
   symbols.push_back("le");
   symbols.push_back("abc");

   vector<string>::iterator it1, it2;

   sort_vector_by_len(symbols);

   for(it1 = names.begin(); it1 != names.end(); it1++)
   {
      for(it2 = symbols.begin(); it2 != symbols.end(); it2++)
      {
         int start = (*it1).find((*it2)), end;

         if(start != string::npos)
         {
            display_new_string(*it1, *it2);
            break;
         }
      }
   }

   printf("\n");

   return 0;
}
