# Currency Converter

A C++ console application that converts currencies using live exchange rates.

## Features

- Convert between different currencies using currency codes
- Retrieves live exchange rates from ExchangeRate-API
- Makes HTTP requests using libcurl
- Parses API responses using nlohmann/json
- Handles invalid currencies and failed API requests
- Stores the API key securely using an environment variable

## Technologies Used

- C++
- libcurl
- nlohmann/json
- ExchangeRate-API
- Git/GitHub

## How It Works

1. The user enters the currency they currently have.
2. The user enters the currency they want to convert to.
3. The user enters an amount.
4. The program sends a request to ExchangeRate-API using libcurl.
5. The JSON response is parsed to retrieve the current conversion rate.
6. The program multiplies the amount by the conversion rate and displays the result.

## Example

```text
Enter the currency you have:
USD

Enter the currency you want to convert to:
EUR

Enter the amount you want to convert: 30

Current conversion rate: 0.8611
30 USD = 25.833 EUR
```

## Building the Project

Compile with:

```powershell
g++ converter-project.cpp converter-functions.cpp -lcurl -o converter-project.exe
```

Run with:

```powershell
.\converter-project.exe
```

## API Key Setup

This project requires an ExchangeRate-API key. The API key is stored in an environment variable so it does not need to be hard-coded into the source code.

### Windows PowerShell

To temporarily set the API key for the current PowerShell session:

```powershell
$env:EXCHANGE_API_KEY="YOUR_API_KEY"
```

To store the API key permanently for your Windows user account:

```powershell
[Environment]::SetEnvironmentVariable("EXCHANGE_API_KEY", "YOUR_API_KEY", "User")
```

Restart the terminal or VS Code after setting the permanent environment variable.

## Dependencies

- libcurl
- nlohmann/json
- ExchangeRate-API key

## What I Learned

Through this project, I learned how to:

- Organize a C++ program across multiple source and header files
- Make HTTP requests using libcurl
- Work with a REST API
- Parse JSON data in C++
- Use environment variables to protect API keys
- Handle API and user input errors
- Use Git and GitHub for version control