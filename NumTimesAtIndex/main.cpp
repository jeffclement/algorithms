#include <cstdio>
#include <algorithm>

#include <iostream>
#include <map>
#include <string>

#include <vector>

void runFindDepth();
int find_depth(const char* s, int startIndex, int& endIndex);
int find_depth(const char* s);


void runPrintValueIndexCount();
void printValueIndexCount(std::vector<std::vector<int> >& list);

int main()
{
  printf("Running main\n");

  runPrintValueIndexCount();

  runFindDepth();

    return 0;
}

/*
Write a function in any language that takes as input a list of lists of integers. The function should return void, and print to standard output the number of times each integer appeared at each index in an inner list. So for instance:
   countem ([ [ 1,2,3], [1,3,4], [1,3] ])
   
Would output:
   1 @ 0 -> 3
   2 @ 1 -> 1
   3 @ 2 -> 1
   3 @ 1 -> 2
   4 @ 2 -> 1 
 */

void runPrintValueIndexCount()
{
  //std::vector<int> list1 = {1};
  //std::vector<int> num1 = { 2, 4, 1, 8};
  std::vector<std::vector<int> > list = { { 1,2,3 }, { 1,3,4 }, { 1,3 } };
  printValueIndexCount(list);
}

void printValueIndexCount(std::vector<std::vector<int> >& list)
{
  std::map<int, std::map<int, int> > m;

  for (int listIndex = 0; listIndex < list.size(); ++listIndex)
  {
    const std::vector<int>& innerList = list.at(listIndex);
    for (int index = 0; index < innerList.size(); ++index)
    {
      int value = innerList.at(index);
      if (m.find(value) == m.end())
      {
        std::map<int, int> innerMap;
        innerMap.insert(std::make_pair(index, 1));
        m.insert(std::make_pair(value, innerMap));
      }
      else if (m.at(value).find(index) == m.at(value).end())
      {
        m.at(value).insert(std::make_pair(index, 1));
      }
      else
      {
        ++m.at(value).at(index);
      }
    }
  }

  for (std::map<int, std::map<int, int> >::iterator it = m.begin(); it != m.end(); ++it)
  {
    int value = it->first;
    std::map<int, int> innerMap = it->second;
    for (std::map<int, int>::iterator j = innerMap.begin(); j != innerMap.end(); ++j)
    {
      printf("%d @ %d -> %d\n", value, j->first, j->second);
    }
  }
}

/*
Consider this string representation for binary trees. Each node is of the form (lr), where l represents the left child and r represents the right child. If l is the character 0, then there is no left child. Similarly, if r is the character 0, then there is no right child. Otherwise, the child can be a node of the form (lr), and the representation continues recursively.
For example: (00) is a tree that consists of one node. ((00)0) is a two-node tree in which the root has a left child, and the left child is a leaf. And ((00)(00)) is a three-node tree, with a root, a left and a right child.
Write a function that takes as input such a string, and returns -1 if the string is malformed, and the depth of the tree if the string is well-formed. Use C, C++ or Java. Hint: trees are recursive data structures!
For instance:
     find_depth('(00)') -> 0
     find_depth('((00)0)') -> 1
     find_depth('((00)(00))') -> 1
     find_depth('((00)(0(00)))') -> 2
     find_depth('((00)(0(0(00))))') -> 3
     find_depth('x') -> -1
     find_depth('0') -> -1
     find_depth('()') -> -1
     find_depth('(0)') -> -1
     find_depth('(00)x') -> -1
     find_depth('(0p)') -> -1
*/
void runFindDepth()
{
  const char* string= 
  //"(00)"; // 0
  //"((00)0)"; //-> 1
  //"((00)(00))"; //-> 1
  //"((00)(0(00)))"; //-> 2
  //"((00)(0(0(00))))"; //-> 3
  //"x"; //-> -1
  //"0"; //-> -1
  //"()"; //-> -1
  //"(0)"; //-> -1
  "(00)x"; //-> -1
  //"(0p)"; // -1
  //"((00)(0(0(00))))"; //-> 3

  int depth = find_depth(string);
  printf("depth = %d string = %s", depth, string);
}

int find_depth(const char* s)
{
  int endIndex = 0;
  int depth = find_depth(s, 0, endIndex);

  printf("endIndex = %d\n", endIndex);
  // if valid string
  if (s[endIndex + 1] == 0)
  {
    return depth;
  }
  else
  {
    return -1;
  }
}

int find_depth(const char* s, int startIndex, int& endIndex)
{
  int index = startIndex;
  if (s[index] != '(')
  {
    endIndex = index;
    return -1;
  }
  index++;
  int leftStartIndex = index;
  if ((s[leftStartIndex] != '(') && (s[leftStartIndex] != '0'))
  {
    return -1;
  }
  int leftEndIndex = leftStartIndex;
  int leftMax = find_depth(s, leftStartIndex, leftEndIndex);

  int rightStartIndex = leftEndIndex + 1;
  if ((s[rightStartIndex] != '(') && (s[rightStartIndex] != '0'))
  {
    return -1;
  }
  int rightEndIndex = rightStartIndex;
  int rightMax = find_depth(s, rightStartIndex, rightEndIndex);

  if (s[rightEndIndex + 1] != ')')
  {
    return -1;
  }
  endIndex = rightEndIndex + 1;

  return std::max<int>(leftMax, rightMax) + 1;
}
