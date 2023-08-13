# Setting Up C++ Authentication System

This guide explains how to set up an authentication system in C++ using a user-defined file for storing credentials. You can provide the credentials file as a command-line argument.

## Loading Usernames and Passwords

Credentials are stored in the file using the following format:

```
usr=<username>
passwd=<password>
```


The program extracts the username and password values by searching for these lines in the file and using the [`find()`](https://cplusplus.com/reference/string/basic_string/find/) function from the [`<string>`](https://cplusplus.com/reference/string/string/) library. The [`substr()`](https://cplusplus.com/reference/string/basic_string/substr/) function is then used to generate substrings based on predetermined lengths:

<details open>
<summary>Credential Value Lengths</summary>

- Username (usr): `4`
- Password (passwd): `7`

</details>

The program truncates everything before the first character after the `=` sign to obtain the actual values.

## Explain

The C++ code provided implements an authentication system. Here's an overview of its functionality:

- The code begins with necessary `#include` statements to include the required C++ standard libraries.

- It defines default values for the username (`DEFAULT_USR`) and password (`DEFAULT_PASSWD`).

- A success message template is defined as `SUCCESS_MSG`.

- A vector named `errorMessages` stores error messages to be displayed during program execution.

- The `Credentials` struct is defined to store username and password.

- The `replaceData()` function replaces occurrences of a string with another string within a given string.

- The `readCredentialsFromFile()` function reads credentials from the provided file name, and if the file doesn't exist, it creates a template file with placeholders.

- The `main()` function is the program's entry point.

- The program searches for the `--file` command-line argument to get the credentials file name.

- If the file name is not provided, it prints the correct usage and exits.

- The program initializes a `Credentials` struct and reads credentials from the file using `readCredentialsFromFile()`.

- It compares the read credentials with default values and prints an error message if they don't match.

- Finally, if the credentials are correct, it prints the success message with the replaced username.

Remember to replace the placeholders in the code with actual values and customize the error messages according to your requirements.

Feel free to use and adapt this code for your authentication needs.
