#ifndef BK_H
#define BK_H

#include "header.h"
#include "dputils.h"

class BKNode
{
    private:
        std::string word;
        std::unordered_map <unsigned, std::shared_ptr<BKNode>> children;
    public:
        BKNode(std::string);
        ~BKNode();
        bool containsKey(unsigned dist) const;
        std::string getWord() const {
            return word;
        }
        std::shared_ptr<BKNode> getChild(unsigned dist) const {
            return children.at(dist);
        }
        void addChild(unsigned, std::string);
        std::vector<unsigned> getKeys() const;
        void displayChildren() const{
            for (auto kv: children){
                kv.second->displayChildren();
                std::cout << std::endl;
            }
        }
        void display() const
        {
            displayChildren();
        }
};

BKNode::BKNode(std::string w)
    :word(w)
{

}

BKNode::~BKNode()
{
}


std::vector<unsigned> BKNode::getKeys() const
{
    std::vector<unsigned> keys;
    keys.reserve(children.size());
    for (auto kvpair:children){
        keys.push_back(kvpair.first);
    }
    return keys;
}


void BKNode::addChild(unsigned dist, std::string childWord){
    children[dist] = std::make_shared<BKNode>(childWord);
}

bool BKNode::containsKey(unsigned dist) const {
    std::unordered_map<unsigned, std::shared_ptr<BKNode> >::const_iterator got = children.find(dist);
    return got != children.end();
}

class BK
{
    private:
        std::shared_ptr<BKNode> root;
        void recursivesearch(std::shared_ptr<BKNode>, unsigned, std::string, std::vector<std::string>&) const;


    public:
        BK();
        ~BK();
        void add(std::string word);
        std::vector<std::string> search(std::string, unsigned) const;
        void displayTree() const;
        
};

BK::BK()
{

}

BK::~BK()
{
    
}

void BK::displayTree() const
{
    if (root != NULL)
    {
        root->display();
    }
}

void BK::recursivesearch(std::shared_ptr<BKNode> node, unsigned int tol, std::string word, std::vector<std::string>& res) const
{
    std::string curWord = node->getWord();
    unsigned curDist = DP::levenshteinDistance(curWord.begin(), curWord.end(), word.begin(), word.end());

    if (curDist <= tol)
    {
        res.push_back(curWord);
    }
    std::vector<unsigned> keys = node->getKeys();

    for (auto k=keys.begin(); k != keys.end(); k++ ){
        if (*k <= curDist+tol && *k >= curDist-tol)
        {
            recursivesearch(node->getChild(*k), tol, word, res);
        }
    }
}

std::vector<std::string> BK::search(std::string word, unsigned tolerance) const
{
    std::vector<std::string> result;
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
 
    recursivesearch(root, tolerance, word, result);
    return result;
}

void BK::add(std::string word)
{
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    if (root == NULL){
        root = std::make_shared<BKNode>(word);
        return;
    }
    std::shared_ptr<BKNode> curNode = root;
    std::string curWord = curNode->getWord();
    unsigned dist = DP::levenshteinDistance(curWord.begin(), curWord.end(), word.begin(), word.end());

    while (curNode->containsKey(dist)){
        if (dist == 0)
            return;
        
        curNode = curNode->getChild(dist);
        curWord = curNode->getWord();
        dist = DP::levenshteinDistance(curWord.begin(), curWord.end(), word.begin(), word.end());
    }

    curNode->addChild(dist, word);

}



#endif
