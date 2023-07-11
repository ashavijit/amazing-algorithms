class Solution
{
public:
    string crackSafe(int n, int k)
    {
        if (k == 1)
            return string(n, '0'); // If k is 1, return a string of n zeros

        int vertices = 1;
        for (int i = 1; i < n; ++i)
        {
            vertices *= k;
        }

        vector<vector<int>> edges(vertices, vector<int>(k, 0)); // Initialize the edges vector

        int edges_cnt = vertices * k; // Total number of remaining edges in the graph

        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                edges[i][j] = 1; // Set all edges to 1 to indicate valid connections
            }
        }

        string answer(vertices * k + n - 1, '0'); // Initialize the answer string with zeros
        int end = n - 1;                          // Current index in the answer string
        int cur_vertex = 0;                       // Current vertex being explored
        vector<char> circuit;                     // Circuit path in case of dead ends

        while (end < answer.size())
        {
            int i;
            for (i = 0; i < k; ++i)
            {
                if (edges[cur_vertex][i] > 0)
                {
                    edges[cur_vertex][i] = 0; // Mark the edge as used
                    --edges_cnt;              // Decrement the count of remaining edges
                    break;
                }
            }

            if (i < k)
            {
                answer[end++] = i + '0'; // Assign the digit to the answer string
                if (edges_cnt == 0)
                    break; // If all edges have been used, exit the loop
            }
            else
            {
                circuit.push_back(answer[end - 1]); // Add the last digit to the circuit vector
                --end;                              // Decrement the end index
            }

            string next = answer.substr(end - n + 1, n - 1).c_str(); // Extract the next n-1 digits
            cur_vertex = 0;
            for (int j = 0; j < next.size(); ++j)
            {
                cur_vertex = cur_vertex * k + next[j] - '0'; // Calculate the next vertex
            }
        }

        for (int i = circuit.size() - 1; i >= 0; --i)
        {
            answer[end++] = circuit[i]; // Add the digits from the circuit to the answer
        }

        return answer;
    }
};


// This Algorithm is called Hierholzer's Algorithm