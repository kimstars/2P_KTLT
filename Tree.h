#pragma once
#include "SapXep.cpp"

#include <vector>

struct TreeNode
{
    SinhVien data;
    TreeNode *left, *right;
};

class BSTtree
{
public:
    TreeNode *root;
    int type;
    int n;

public:
    BSTtree()
    {
        root = NULL;
        type = 0;
        n = 0;
    }

    ~BSTtree(){};

    int LeftOf(TreeNode *value, TreeNode *root, int type)
    {
        return soSanh(value->data, root->data, type) == -1;
    }

    int RightOf(TreeNode *value, TreeNode *root, int type)
    {
        return soSanh(value->data, root->data, type) != -1;
    }

    TreeNode *newTreeNode(SinhVien sv)
    {
        TreeNode *temp = new TreeNode;
        temp->data = sv;
        temp->left = temp->right = NULL;
        return temp;
    }

    TreeNode *Insert(TreeNode *t, SinhVien data, int type)
    {
        TreeNode *tempTreeNode = newTreeNode(data);
        if (t == NULL){
            return tempTreeNode; // neu tree rong ra ve node moi
        }

        if (LeftOf(t, tempTreeNode, type))
        {
            t->left = Insert(t->left, data, type);
        }
        else if (RightOf(t, tempTreeNode, type))
        {
            t->right = Insert(t->right, data, type);
        }
        return t;
    }

    void PreOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            cout << (root->data);
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }

    // search cay nhi phan tim kiem
    SinhVien SearchTree(TreeNode *root, TreeNode *value, string s, int type)
    {
        // cout << root->data;
        if (root == NULL)
        {

            return root->data;
        }

        if (soSanh(root->data, value->data, type) == 0)
        {
            return root->data;
        }
        else if (LeftOf(value, root, type))
        {
            return SearchTree(root->left, value, s, type);
        }
        else if (RightOf(value, root, type))
        {
            return SearchTree(root->right, value, s, type);
        }
    }

    void readTREE(vector<SinhVien> ds)
    {
        vector<SinhVien> ds2;
        for (int i = 0; i < ds.size(); i++)
        {
            cout << i;
            root = Insert(root, ds[i], type);
        }
    }
};