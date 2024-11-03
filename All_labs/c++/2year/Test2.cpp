#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

// Function to compute the hash based on the provided formula
long long compute_hash(const string& s) {
    long long hash_value = 0;
    long long power_of_11 = 1; // To calculate 11^i

    for (size_t i = 0; i < s.length(); i++) {
        hash_value = (hash_value + (s[i] - '0') * power_of_11) % MOD;
        power_of_11 = (power_of_11 * 11) % MOD; // Update 11^i
    }

    return (hash_value * -47) % MOD; // Applying the formula and returning the correct hash
}

int main() {
    int N;
    cin >> N;
    vector<string> inputs(2 * N);
    
    for (int i = 0; i < 2 * N; i++) {
        cin >> inputs[i]; // Read all strings and hashes
    }

    unordered_map<long long, string> hash_to_string; // Maps hash values to strings
    unordered_map<string, long long> string_to_hash; // Maps strings to their hash values

    // Process the inputs to compute hashes for strings
    for (int i = 0; i < 2 * N; i++) {
        const string& s = inputs[i];
        // Check if the string is composed only of digits
        if (all_of(s.begin(), s.end(), ::isdigit)) {
            long long hash_value = compute_hash(s);
            string_to_hash[s] = hash_value; // Store the hash for the string
            hash_to_string[hash_value] = s; // Also map the computed hash back to the string
        } else {
            try {
                long long hash_value = stoll(s); // Convert the input to a long long
                hash_to_string[hash_value] = ""; // Placeholder for the string
            } catch (...) {
                continue; // If conversion fails, skip (should not happen as per the problem statement)
            }
        }
    }

    // Output the results in the order of original input
    for (int i = 0; i < 2 * N; i++) {
        const string& s = inputs[i];
        if (all_of(s.begin(), s.end(), ::isdigit)) {
            long long hash_value = string_to_hash[s]; // Get the hash value of the string
            cout << "Hash of string \"" << s << "\" is " << hash_value << endl;
        } else {
            try {
                long long hash_value = stoll(s);
                if (hash_to_string.find(hash_value) != hash_to_string.end()) {
                    // Print the corresponding string for the hash
                    cout << "Hash of string \"" << hash_to_string[hash_value] << "\" is " << s << endl;
                }
            } catch (...) {
                continue; // If conversion fails, skip (should not happen as per the problem statement)
            }
        }
    }

    return 0;
}
