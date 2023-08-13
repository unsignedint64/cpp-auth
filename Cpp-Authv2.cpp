#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


#define DEFAULT_USR "admin"
#define DEFAULT_PASSWD "admin"

#define SUCCESS_MSG "Success! Welcome <<usr>>! :)"

/// <summary>
/// Stores the error messages
/// </summary>
const std::vector<std::string> errorMessages = {
	"We couldn't find the credentials file: <<fileName>>. However we created a template file for you!",
	"Invalid credentials"
};


/// <summary>
/// Stores the credentials
/// </summary>
struct Credentials
{
	std::string usr;
	std::string passwd;
};


/// <summary>
/// Replaces all occurrences of toReplace with replaceWith in str
/// </summary>
/// <param name="str"></param>
/// <param name="toReplace"></param>
/// <param name="replaceWith"></param>
/// <returns></returns>
std::string replaceData(const std::string& str, const std::string& toReplace, const std::string& replaceWith)
{
	std::string result = str;

	// Find the position of the first occurrence of toReplace
	size_t pos = result.find(toReplace);

	// Loop while the position is not equal to std::string::npos
	while (pos != std::string::npos) {
		// Replace the toReplace with replaceWith
		result.replace(pos, toReplace.length(), replaceWith);

		// Find the position of the next occurrence of toReplace
		pos = result.find(toReplace);
	}

	return result;
}


/// <summary>
/// Reads the credentials from the file
/// </summary>
/// <param name="fileName"></param>
/// <param name="credentials"></param>
/// <returns></returns>

bool readCredentialsFromFile(const std::string& fileName, Credentials& credentials)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		// Create the file

		std::ofstream file(fileName);

		// Write this to the file
		// usr=
		// passwd=

		file << "/*" << std::endl;
		file << "  usr; Is the username of the program." << std::endl;
		file << "  passwd; Is the password of the program." << std::endl;
		file << std::endl;
		file << " If you are unsure about what to do, please read the ./SETUP.md file." << std::endl;
		file << "*/" << std::endl;
		file << std::endl;
		file << "usr=" << std::endl;
		file << "passwd=" << std::endl;

		file.close();

		std::cerr << replaceData(errorMessages[0], "<<fileName>>", fileName) << std::endl;

		return false;
	}

	std:: string line;
	
	while (std::getline(file, line)) {
		if (line.find("usr=") != std::string::npos) {
			credentials.usr = line.substr(4);
		}
		else if (line.find("passwd=") != std::string::npos) {
			credentials.passwd = line.substr(7);
		}
	}

	file.close();

	return true;
}

int main(int argc, char* argv[])
{
    // Get the --file argument
	std::string fileName;

	// Loop through the arguments
	if (argc > 1) {
		// Check if the --file argument was provided
		for (int i = 1; i < argc; i++) {
			// Check if the argument is --file
			if (std::string(argv[i]) == "--file") {
				// Check if there is another argument after --file
				if (i + 1 < argc) {
					// Set the fileName to the next argument, and break out of the loop
					fileName = argv[i + 1];
					break;
				}
			}
		}
	}

	// Check if the --file argument was provided
	if (fileName.empty()) {
		// If not, print the usage and return
		std::cerr << "Usage: " << argv[0] << " --file <credentials file>" << std::endl;
		return 1;
	}

	Credentials credentials;

	// Read the credentials from the file
	if (!readCredentialsFromFile(fileName, credentials)) return 1;

	// Check if the credentials are correct (usr and passwd)
	if (credentials.usr != DEFAULT_USR || credentials.passwd != DEFAULT_PASSWD) {
		std::cerr << errorMessages[1] << std::endl;
		return 1;
	}

	// Print the success message
	std::cout << replaceData(SUCCESS_MSG, "<<usr>>", credentials.usr) << std::endl;


	return 0;
}