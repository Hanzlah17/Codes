#include<iostream>
#include<string>
#include <queue>
#include<fstream>
#include <bitset>
#include <unordered_map>
using namespace std;

string charToBinary(char character)
{
    bitset<8> binaryRepresentation(character);
    return binaryRepresentation.to_string();
}

string stringToBinary(string inputString)
{
    string binaryResult = "";
    for (char character : inputString)
    {
        binaryResult += charToBinary(character);
    }
    return binaryResult;
}




class skillNode
{
public:
	int level; 
	string name;
	skillNode* left;
	skillNode* right;
	skillNode(int l, string n)
	{
		level = l;
		name = n;
		left = nullptr;
		right = nullptr;
	}
};
class skillTree 
{
    void inorderTraversal(skillNode* node)
    {
        if (node)
        {
            inorderTraversal(node->left);
            cout << "Level: " << node->level << ", Name: " << node->name << endl;
            inorderTraversal(node->right);
        }
    }
    bool hasSkill(skillNode* node, string skillName)
    {
        if (!node) 
        {
            return false;
        }

        if (node->name == skillName)
        {
            return true;
        }

        return hasSkill(node->left, skillName) || hasSkill(node->right, skillName);
    }
    bool hasExactSkill(skillNode* node, string skillName,int level)
    {
        if (!node)
        {
            return false;
        }
        if (node->name == skillName && node->level>=level)
        {
            return true;
        }
        return hasExactSkill(node->left, skillName,level) || hasExactSkill(node->right, skillName,level);
    }
public:
	skillNode* root;
    skillTree()
    {
        root = nullptr;
    }
    void Print()
    {
        inorderTraversal(root);
    }
    void insert(int level, string name)
    {
        skillNode* newNode = new skillNode(level, name);
        if (!root)
        {
            root = newNode;
            return;
        }
        queue<skillNode*> q;
        q.push(root);

        while (!q.empty()) {
            skillNode* current = q.front();
            q.pop();

            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }

            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }
    bool hasSkill(string skillName)
    {
        return hasSkill(root, skillName);
    }
    bool hasExactSkill(string skillName,int level)
    {
        if (level == 3)
        {
            maxHeap();
        }
        else if (level == 1)
        {
            minHeap();
        }
        return hasExactSkill(root, skillName,level);
    }
    bool isPresent(skillNode* taskroot)
    {
        if (!taskroot)
        {
            return false;
        }
        queue<skillNode*> nodeQueue;
        nodeQueue.push(taskroot);

        while (!nodeQueue.empty()) 
        {
            skillNode* current = nodeQueue.front();
            if (!hasSkill(current->name))
            {
                return false;
            }
            if (current->left)
            {
                nodeQueue.push(current->left);
            }
            if (current->right) 
            {
                nodeQueue.push(current->right);
            }

            nodeQueue.pop();
        }
        return true;
    }
    bool isExactPresent(skillNode* taskroot)
    {
        if (!taskroot)
        {
            return false;
        }
        queue<skillNode*> nodeQueue;
        nodeQueue.push(taskroot);

        while (!nodeQueue.empty())
        {
            skillNode* current = nodeQueue.front();
            if (!hasExactSkill(current->name,current->level))
            {
                return false;
            }
            if (current->left)
            {
                nodeQueue.push(current->left);
            }
            if (current->right)
            {
                nodeQueue.push(current->right);
            }

            nodeQueue.pop();
        }
        return true;
    }
    void minHeap(skillNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        minHeap(node->left);
        minHeap(node->right);
        heapifyMin(node);
    }
    void maxHeap(skillNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        maxHeap(node->left);
        maxHeap(node->right);

        heapifyMax(node);
    }
    void maxHeap()
    {
        maxHeap(root);
    }
    void minHeap()
    {
        minHeap(root);
    }
    void heapifyMin(skillNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        skillNode* smallest = node;
        skillNode* left = node->left;
        skillNode* right = node->right;

        if (left != nullptr && left->level < smallest->level)
        {
            smallest = left;
        }

        if (right != nullptr && right->level < smallest->level)
        {
            smallest = right;
        }

        if (smallest != node)
        {
            swap(node->level, smallest->level);
            swap(node->name, smallest->name);
            heapifyMin(smallest);
        }
    }
    void heapifyMax(skillNode* node)
    {
        if (node == nullptr) return;

        skillNode* largest = node;
        skillNode* left = node->left;
        skillNode* right = node->right;

        if (left != nullptr && left->level > largest->level)
        {
            largest = left;
        }

        if (right != nullptr && right->level > largest->level)
        {
            largest = right;
        }

        if (largest != node)
        {
            swap(node->level, largest->level);
            swap(node->name, largest->name);
            heapifyMax(largest);
        }
    }
};
class resourceNode
{
public:
	string name;
	skillTree* SkillTree;
	resourceNode* left;
	resourceNode* right;

    resourceNode(string n)
    {
        name = n;
        SkillTree = new skillTree;
        left = right = nullptr;
    }
};
class resourceTree
{

    void inorderHelper(resourceNode* node) 
    {
        if (node) 
        {
            inorderHelper(node->left);

            cout << "Resource Name: " << node->name << endl;
            if (node->SkillTree) 
            {
                cout << "Skills:" << endl;
                node->SkillTree->Print();
            }

            inorderHelper(node->right);
        }
    }
public:
	resourceNode* root;
    resourceTree()
    {
        root = nullptr;
    }
    void levelOrderInsert(resourceNode* newNode)
    {
        if (!root) 
        {
            root = newNode;
            return;
        }

        queue<resourceNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            resourceNode* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            else 
            {
                q.push(current->left);
            }

            if (current->right == nullptr) 
            {
                current->right = newNode;
                return;
            }
            else 
            {
                q.push(current->right);
            }
        }
    }
    void buildFromFile()
    {
        ifstream resourcefile;
        resourcefile.open("resource.txt");
        while (!resourcefile.eof())
        {
            string line;
            getline(resourcefile, line);
            int  length = line.length();
            if (length == 0)
            {
                return;
            }
            int i = 0;
            string name;
            while (line[i] != '|')
            {
                name+= line[i];
                i++;
            }
            resourceNode* newNode = new resourceNode(name);
            levelOrderInsert(newNode);
            while (i<length)
            {
                i++;
                string skillName;
                while (line[i] != ':')
                {
                    skillName+= line[i];
                    i++;
                }
                i++;
                int level = line[i] - '0';
                newNode->SkillTree->insert(level, skillName);
                i++;
            }
       
        }
        resourcefile.close();
    }
    void Print()
    {
        inorderHelper(root);
    }
};
class taskNode
{
public:
	string name;
	skillTree* skills;
	taskNode* left;
	taskNode* right;
    taskNode(string n)
    {
        name = n;
        skills = new skillTree;
        left = right = nullptr;
    }

};
class taskTree
{
   
    void inorderHelper(taskNode* node)
    {
        if (node)
        {
            inorderHelper(node->left);

            cout << "Resource Name: " << node->name << endl;
            if (node->skills)
            {
                cout << "Skills:" << endl;
                node->skills->Print();
            }

            inorderHelper(node->right);
        }
    }
public:
	taskNode* root;
    taskTree()
    {
        root = nullptr;
    }
    taskNode* getRoot()
    {
        return root;
    }
    void levelOrderInsert(taskNode* newNode)
    {
        if (!root)
        {
            root = newNode;
            return;
        }

        queue<taskNode*> q;
        q.push(root);

        while (!q.empty())
        {
            taskNode* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }

            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }
    void buildFromFile()
    {
        ifstream taskfile;
        taskfile.open("task.txt");
        while (!taskfile.eof())
        {
            string line;
            getline(taskfile, line);
            int  length = line.length();
            if (length == 0)
            {
                return;
            }
            int i = 0;
            string name;
            while (line[i] != '|')
            {
                name += line[i];
                i++;
            }
            taskNode* newNode = new taskNode(name);
            levelOrderInsert(newNode);
            while (i < length)
            {
                i++;
                string skillName;
                while (line[i] != ':')
                {
                    skillName += line[i];
                    i++;
                }
                i++;
                int level = 0;
                if (line[i] == 'e')
                {
                    level = 3;
                }
                else if (line[i] == 'i')
                {
                    level = 2;
                }
                else
                {
                    level = 1;
                }
                newNode->skills->insert(level, skillName);
                i++;
            }

        }
        taskfile.close();
    }
    void Print()
    {
        inorderHelper(root);
    }
};
bool skillMatch(resourceNode* resource, taskNode* task) 
{
    return resource->SkillTree->isPresent(task->skills->root);
}
bool ExactMatch(resourceNode* resource, taskNode* task)
{
    return resource->SkillTree->isExactPresent(task->skills->root);
}
class AllocationNode
{
public:
	string taskName;
    string decodedstr;
	AllocationNode* left;
	AllocationNode* right;
    AllocationNode(string task,string res)
    {
        taskName = task;
        decodedstr = stringToBinary(res);
        left = right = nullptr;
    }
    void growstring(string res)
    {
        decodedstr += stringToBinary(res);
    }
};
class AllocationTree
{
public:
	AllocationNode* root;
    AllocationTree()
    {
        root = nullptr;
    }
    void insert(AllocationNode* newNode)
    {
        if (!root)
        {
            root = newNode;
            return;
        }
        queue<AllocationNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            AllocationNode* current = q.front();
            q.pop();

            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }

            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }
    
};
class Helper
{
public:
    AllocationTree tree;
    void BuildAllocationNode(taskNode* node,resourceNode* rRoot)
    {
        queue<resourceNode*> nodeQueue;
        AllocationNode* nn = 0;
        nodeQueue.push(rRoot);

        while (!nodeQueue.empty())
        {
            resourceNode* current = nodeQueue.front();
            if (skillMatch(current, node))
            {
                if (!nn)
                {
                    nn = new AllocationNode(node->name, current->name);
                    tree.insert(nn);
                }
                else
                {
                    nn->growstring(current->name);
                }
            }
            if (current->left)
            {
                nodeQueue.push(current->left);
            }
            if (current->right)
            {
                nodeQueue.push(current->right);
            }
            nodeQueue.pop();
        }
    }
    void BuildExactAllocationNode(taskNode* node, resourceNode* rRoot)
    {
        queue<resourceNode*> nodeQueue;
        AllocationNode* nn = 0;
        nodeQueue.push(rRoot);

        while (!nodeQueue.empty())
        {
            resourceNode* current = nodeQueue.front();
            if (ExactMatch(current, node))
            {
                if (!nn)
                {
                    nn = new AllocationNode(node->name, current->name);
                    tree.insert(nn);
                }
                else
                {
                    nn->growstring(current->name);
                }
            }
            if (current->left)
            {
                nodeQueue.push(current->left);
            }
            if (current->right)
            {
                nodeQueue.push(current->right);
            }
            nodeQueue.pop();
        }
    }
    void BuildAllocationTree(taskNode* Troot,resourceNode* Rroot,bool b)
    {
        if (!Troot)
        {
            return;
        }
        if (b == 1)
        {
            BuildAllocationNode(Troot, Rroot);
        }
        else
        {
            BuildExactAllocationNode(Troot, Rroot);
        }
        BuildAllocationTree(Troot->left,Rroot,b);
        BuildAllocationTree(Troot->right,Rroot,b);
    }
};
void StoreDataInFile(AllocationNode* root,fstream& file)
{
    if (!root)
    {
        return;
    }
    file << root->taskName << "\n"<<root->decodedstr<<"\n";
    StoreDataInFile(root->left, file);
    StoreDataInFile(root->right, file);
}
void BuildHuffmanFile(AllocationNode* root, fstream& file,string str)
{
    if (!root)
    {
        return;
    }
    file << str << "\n";
    BuildHuffmanFile(root->left, file, str + "0");
    BuildHuffmanFile(root->right, file, str + "1");
}
void main()
{
    resourceTree resourcetree;
    taskTree tasktree;
    resourcetree.buildFromFile();
    tasktree.buildFromFile();
    Helper obj;
    bool strat = 0;
    cout << "Press 0 for ExactMatch and 1 for skillMatch\n";
    cin >> strat;
    obj.BuildAllocationTree(tasktree.root, resourcetree.root, strat);
    fstream file;
    file.open("output.txt", ios::app);
    StoreDataInFile(obj.tree.root, file);
    file.close();
    fstream cfile;
    cfile.open("compressed.txt", ios::app);
    BuildHuffmanFile(obj.tree.root, cfile, "0");
}