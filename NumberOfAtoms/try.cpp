class Solution
{
private:
    // Data structure to represent the AST node
    struct ASTNode
    {
        string name;
        int count;
        unordered_map<string, int> subAtoms;

        ASTNode(string name, int count) : name(name), count(count) {}
    };

    // Function to parse the formula and build the AST
    ASTNode *parseFormula(string &formula, int &index)
    {
        ASTNode *root = new ASTNode("", 1);
        string atom = "";

        while (index < formula.length())
        {
            char c = formula[index];

            if (c == '(')
            {
                index++;                                          // Move past '('
                ASTNode *subgroup = parseFormula(formula, index); // Parse the subgroup recursively
                index++;                                          // Move past ')'

                int count = 1;
                if (isdigit(formula[index]))
                {
                    count = 0;
                    while (index < formula.length() && isdigit(formula[index]))
                    {
                        count = count * 10 + (formula[index] - '0');
                        index++;
                    }
                }

                // Merge the counts of subAtoms from the subgroup into the root node
                for (const auto &[subAtom, subCount] : subgroup->subAtoms)
                {
                    root->subAtoms[subAtom] += subCount * count;
                }
                delete subgroup;
            }
            else if (isupper(c))
            {
                atom = c;
                index++;
                while (index < formula.length() && islower(formula[index]))
                {
                    atom += formula[index];
                    index++;
                }

                int count = 1;
                if (isdigit(formula[index]))
                {
                    count = 0;
                    while (index < formula.length() && isdigit(formula[index]))
                    {
                        count = count * 10 + (formula[index] - '0');
                        index++;
                    }
                }

                // Store the count of the current atom in the root node's subAtoms
                root->subAtoms[atom] += count;
            }
            else
            {
                break; // If not an upper case letter or '(', stop parsing
            }
        }

        return root;
    }

    // Function to count atoms from the AST and store them in a map
    void countAtomsFromAST(ASTNode *node, unordered_map<string, int> &atomCounts)
    {
        if (node->name != "")
        {
            atomCounts[node->name] += node->count;
        }

        // Recursively count the subAtoms
        for (const auto &[subAtom, subCount] : node->subAtoms)
        {
            atomCounts[subAtom] += subCount;
        }
    }

public:
    string countOfAtoms(string formula)
    {
        int index = 0;
        ASTNode *root = parseFormula(formula, index); // Parse the formula and build the AST

        unordered_map<string, int> atomCounts;
        countAtomsFromAST(root, atomCounts); // Count the atoms from the AST

        delete root; // Clean up the memory used by the AST

        string result = "";
        for (const auto &[atom, count] : atomCounts)
        {
            result += atom;
            if (count > 1)
            {
                result += to_string(count); // Append the atom count if it's greater than 1
            }
        }

        return result;
    }
};
