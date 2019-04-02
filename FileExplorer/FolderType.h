#ifndef _FOLDERTYPE_H
#define _FOLDERTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <time.h>
#include <iomanip>

using namespace std;

// 서로 include 하는 에러 막기 위해 include 하기 전 이름 선언
class SortedArrayList;

/**
*	Relation between two items.
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	item information class.
*/
class FolderType
{
public:
	/**
	*	default constructor.
	*/
	FolderType()
	{
		id_ = -1;
		size_ = 0;
		num_sub_folder_ = 0;
		name_ = "";
		path_ = "";
		GenerateCreatedDate();
	}

	/**
	*	destructor.
	*/
	~FolderType()	{
		if (num_sub_folder_ != 0) {
			delete sub_folder_list_;
		}
	}

	/**
	*	@brief	Get folder id.
	*	@pre	folder id is set.
	*	@post	none.
	*	@return	folder id.
	*/
	int GetId()
	{
		return id_;
	}

	/**
	*	@brief	Get folder size.
	*	@pre	folder size is set.
	*	@post	none.
	*	@return	folder size.
	*/
	int GetSize() {
		return size_;
	}

	/**
	*	@brief	Get number of sub folders.
	*	@pre	number of sub folder is set
	*	@post	none.
	*	@return	number of sub folders.
	*/
	int GetNumSubFolder() {
		return num_sub_folder_;
	}

	/**
	*	@brief	Get copy of sub folders list.
	*	@pre	sub folders are set
	*	@post	none.
	*	@return	address of sub folders list.
	*/
	const SortedArrayList* GetSubFolders() {
		return sub_folder_list_;
	}

	/**
	*	@brief	Get folder name.
	*	@pre	folder name is set.
	*	@post	none.
	*	@return	folder name.
	*/
	string GetName()
	{
		return name_;
	}

	/**
	*	@brief	Get folder path
	*	@pre	folder path is set.
	*	@post	none.
	*	@return	folder path.
	*/
	string GetPath()
	{
		return path_;
	}

	/**
	*	@brief	Get created date.
	*	@pre	folder path is set.
	*	@post	none.
	*	@return	folder path.
	*/
	string GetCreatedDate() {
		return created_date_;
	}

	/**
	*	@brief	Set folder id.
	*	@pre	none.
	*	@post	folder id is set.
	*	@param	input_id	folder id.
	*/
	void SetId(int input_id)
	{
		id_ = input_id;
	}

	/**
	*	@brief	Set folder name.
	*	@pre	none.
	*	@post	folder name is set.
	*	@param	input_name	folder name.
	*/
	void SetName(string input_name)
	{
		name_ = input_name;
	}
	
	/**
	*	@brief	Set folder path.
	*	@pre	none.
	*	@post	folder path is set.
	*	@param	input_path	folder path.
	*/
	void SetPath(string input_path)
	{
		path_ = input_path;
	}
	
	/**
	*	@brief	Generate folder's created date.
	*	@pre	none.
	*	@post	folder's created date is set.
	*/
	void GenerateCreatedDate();

	/**
	*	@brief	Set folder record.
	*	@pre	none.
	*	@post	folder record is set.
	*	@param	input_id	folder id.
	*	@param	input_name	folder name.
	*	@param	input_address	folder path.
	*/
	void SetRecord(int input_id, string input_name, string input_path)
	{
		SetId(input_id);
		SetName(input_name);
		SetPath(input_path);
		//GenerateCreatedTime()
	}

	/**
	*	@brief	Display folder id on screen.
	*	@pre	folder id is set.
	*	@post	folder id is on screen.
	*/
	void DisplayIdOnScreen() 
	{
		cout << "\tID   : " << id_ << endl; 
	};

	/**
	*	@brief	Display folder size on screen.
	*	@pre	folder size is set.
	*	@post	folder size is on screen.
	*/
	void DisplaySizeOnScreen() {
		cout << "\tFolder Size : " << size_ << endl;
	};

	/**
	*	@brief	Display number of sub folders on screen.
	*	@pre	num_sub_folder is set.
	*	@post	number of sub folders is on screen.
	*/
	void DisplayNumOfSubFoldersOnScreen() {
		cout << "\tNumber of Sub folders : " << size_ << endl;
	};

	/**
	*	@brief	Display folder name on screen.
	*	@pre	folder name is set.
	*	@post	folder name is on screen.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName : " << name_ << endl; 
	};

	/**
	*	@brief	Display folder path on screen.
	*	@pre	folder path is set.
	*	@post	folder path is on screen.
	*/
	void DisplayPathOnScreen() 
	{
		cout << "\tPath : " << path_ << endl; 
	};

	/**
	*	@brief	Display folder's created date on screen
	*	@pre	folder's created time is set.
	*	@post	folder's  is on screen.
	*/
	void DisplayCreatedDateOnScreen() {
		cout << "\tCreated date : " << created_date_ << endl;
	};

	/**
	*	@brief	Display an folder record on screen.
	*	@pre	folder record is set.
	*	@post	folder record is on screen.
	*/
	void DisplayInformationOnScreen()
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
		DisplayPathOnScreen();
	};

	/**
	*	@brief	Set folder id from keyboard.
	*	@pre	none.
	*	@post	folder id is set.
	*/
	void SetIdFromKeyboard();

	/**
	*	@brief	Set folder name from keyboard.
	*	@pre	none.
	*	@post	folder name is set.
	*/
	void SetNameFromKeyboard();

	/**
	*	@brief	Set folder path from keyboard.
	*	@pre	none.
	*	@post	folder path is set.
	*/
	void SetPathFromKeyboard();
	
	/**
	*	@brief	Set folder record from keyboard.
	*	@pre	none.
	*	@post	folder record is set.
	*/
	void SetRecordFromKeyboard();

	/**
	*	@brief	Copy parameter folder and assign to this folder.
	*	@pre	copide_data is set.
	*	@post	folder record is set.
	*   @param  copied_data    data to assign
	*   @return retrun this after assigning parameter.
	*/
	FolderType& operator= (const FolderType& copied_data);

	/**
	*	@brief	Add sub folder of this folder.
	*	@pre	none.
	*	@post	new sub folder is added.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddSubFolder();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	folder record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new folder record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id, 
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const FolderType &data);

	/**
	*	@brief  Delete sub folder by id
	*	@pre	sub folder list is set.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteFolder();

	/**
	*	@brief  Retrieve folder by folder name.
	*	@pre	sub folder list is set.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetrieveFolderByName();

	/**
	*	@brief  Display all sub folders information on screen.
	*	@pre	sub folder list is set.
	*	@post	sub folder list is diaplyed on screen.
	*/
	void DisplayAllSubFolders();

protected:
	int id_;			///< folder ID.
	int size_;          ///< folder size.
	int num_sub_folder_;    ///< number of sub folders.
	string name_;		///< folder name.
	string path_;       ///< folder path.
	string created_date_;    ///< date that folder created.
	SortedArrayList* sub_folder_list_;   ///< sorted sub folder list
};

#endif	// _FOLDERTYPE_H
