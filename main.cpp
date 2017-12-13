/******************************************************************************
 * AUTHORS        : Jesus Sanchez
 * ASSIGNMENT #14 : Huffman Coding
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 12/13/2017
 *****************************************************************************/

#include "Header.h"
#include "HuffmanTree.h"

/******************************************************************************
 * HUFFMAN CODING
 * ----------------------------------------------------------------------------
 * This program will encode the Gettysberg Address using a Huffman Coding
 * algorithm and then decode the text by converting each code into the
 * appropriate symbol so that the original text is reproduced. Once the encoded
 * Gettysberg Address has been decoded, the compression ratio will be printed.
 * ----------------------------------------------------------------------------
 * INPUT:
 *    <There is no input.>
 *
 * OUTPUT:
 *    - Frequency Table
 *    - Huffman Codes
 *    - Encoded Text
 *    - Decoded Text
 *    - Compression Ratio
 *****************************************************************************/
int main()
{
	cout << "**************************************\n"
		 << "* NAME           : Jesus Sanchez     *\n"
		 << "* ASSIGNMENT #14 : Huffman Coding    *\n"
		 << "* CLASS          : CS1D - MW: 3:00pm *\n"
		 << "* DUE DATE       : 12/13/2017        *\n"
		 <<	"**************************************\n\n"
		 << "DESCRIPTION: This program will encode the Gettysberg Address using\n"
		 	"a Huffman Coding algorithm and then decode the text by converting\n"
		 	"each code into the appropriate symbol so that the original text is\n"
		 	"reproduced. Once the encoded Gettysberg Address has been decoded,\n"
		 	"the compression ratio will be printed. \n\n";

	cout << "**********\n"
			"* PART A *\n"
			"**********\n\n";

	// Returns the text in the file.
	vector<char> text = getText("InFile.txt");

	// Determines the frequency of each character in the text.
	vector<Symbol> symbols = getSymbolFrequencies(text);

	HuffmanTree huffTree;

	huffTree.buildEncodingTree(symbols);

	cout << "Printing the frequency table and Huffman Codes for the symbols.\n\n";

	// Prints the frequency table and code for each symbol in the text.
	cout << left
		 << setw(12) << "SYMBOL" << setw(15) << "FREQUENCY" << setw(12) << "CODE"
		 << endl
		 << setw(12) << "------" << setw(15) << "---------" << setw(12) << "----"
		 << endl;

	for(uint i = 0; i < symbols.size(); i++)
	{
		if(symbols[i].getSymbol() == ' ')
		{
			cout << setw(12) << " space";
		}
		else if(symbols[i].getSymbol() == '\n')
		{
			cout << setw(12) << "  \\n";
		}
		else
		{
			cout << "   " << setw(9) << symbols[i].getSymbol();
		}

		cout << "   " << setw(12) << symbols[i].getFrequency()
								  << symbols[i].getCode() << endl;
	}

	cout << "\n**********\n"
			"* PART B *\n"
			"**********\n\n";

	cout << "Encoding Gettysburg Address...\n\n";

	vector<string> encodedText = encodeText(text, symbols);

	cout << "**********\n"
			"* PART C *\n"
			"**********\n\n";

	cout << "Printing the encoded Gettysberg Address...\n\n";

	uint i = 0;

	// Prints the encoded text while ensuring that the maximum length of any line
	// is no greater than the bound (76).
	while(i < encodedText.size())
	{
		string line;

		uint length = 0;

		// Adds the codes to the current line of the encoded text.
		while(length < BOUND && i < encodedText.size())
		{
			// Checks to see if adding the next code to the current line of text
			// will cause the length of the line to exceed the bound.
			if(length + encodedText[i].size() < BOUND)
			{
				// Adds the code to the current line.
				line += encodedText[i];

				// Accumulates length to store the new size of the line.
				length += encodedText[i].size();

				// Increments i to the next index in encodedText.
				i++;
			}
			else
			{
				// Assigns 100 to length to indicate that adding the next code
				// to the current line will exceed the bound.
				length = 100;
			}
		}

		// Prints the line of encoded text.
		cout << line << endl;
	}

	cout << "\n**********\n"
			"* PART D *\n"
			"**********\n\n";

	cout << "Now decoding the encoded Gettysberg Address...\n\n";

	// Decodes the text and stores the decoded symbols in a vector of characters.
	vector<char> decodedText = decodeText(encodedText, symbols);

	uint j = 0;

	// Prints the decoded text while ensuring that the length of any line does
	// not exceed the bound.
	while(j < decodedText.size())
	{
		string line;

		uint length = 0;

		// Adds characters to the line until a newline is reached or a space is
		// reached and adding the word before the previous space has exceeded
		// the bound.
		while(length < BOUND && j < decodedText.size())
		{
			line += decodedText[j];

			// Checks if the last symbol added was a new line.
			if(decodedText[j] == '\n')
			{
				// Exits to signify that the paragraph ends here.
				length = 100;
			}
			else
			{
				// Increments length and continues the loop.
				length++;
			}

			// Increments j to the next symbol in the decodedText vector.
			j++;
		}

		// If last symbol in the line is not a newline or a punctuation mark,
		// checks if the last symbol is a space.
		if(line.back() != '\n' && line.back() != '.' && line.back() != '!')
		{
			// If the last symbol is not a space, removes the last symbol from
			// the line until it is a space since the bound was exceeded and the
			// entire word may not have been stored in the line.
			if(line.back() != ' ')
			{
				while(line.back() != ' ' && !line.empty())
				{
					line.pop_back();

					// Decrements j to start at the beginning of the word that
					// was just removed from the line in the next loop iteration.
					j--;
				}
			}
		}

		// Prints the line if it is not empty.
		if(!line.empty())
		{
			cout << line << endl;
		}
	}

	cout << "\n**********\n"
			"* PART E *\n"
			"**********\n\n";

	double compressionRatio = 0.0;

	// Finds the compressed length of the text.
	for(uint i = 0; i < symbols.size(); i++)
	{
		compressionRatio += (symbols[i].getFrequency() * symbols[i].getCode().size());
	}

	// Divides by 8 to store the number of bytes in the compressed text.
	compressionRatio /= 8.0;

	// Divides the number of bytes by the number of symbols in the text to
	// get the compression ratio.
	compressionRatio /= double(text.size());

	// Prints the compression ratio to 2 decimal places.
	cout << fixed << setprecision(2)
		 << "Compression Ratio = " << compressionRatio * 100 << "%";

	return 0;
}
