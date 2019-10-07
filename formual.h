#include<string>
#include<list>

enum formType {sqrt, inte, frac, mat};

class maker;

class formual
{
private:
	bool verify()
	{
		return x1!=-1 && y1!=-1 && fontSize!=-1;
	}
	
	string formStr;
	
public:
	virtual int getType()=0;
	formual(string formStr) : formStr(formStr) {}
	float x1=-1;
	float y1=-1;
	int fontSize=-1;
	virtual void draw()=0;
	//父节点管理子节点所有权
	maker* supMaker=nullptr;
	maker* subMaker=nullptr;
	
	~formual()
	{
		delete supMaker;
		delete subMaker;
	}
};

class maker
{
private:
	bool makerFlag; //true为上标
	formual* form;
	
public:
	maker(bool markFlag, formual* form) : 
		markFlag(markFlag), form(form) {}
	void draw()
	{
		//fix:根据上下标计算form的三个量
		form->draw();
	}
	
	~marker()
	{
		delete form;
	}
};

class sqrtForm : public formual
{
private:
	formual* form;
	
public:
	int getType() { return sqrt; }
	sqrtForm(formual *form) : form(form) {}
	//这里应该加一个是根号或是什么的flag
	void draw();
	~sqrtForm()
	{
		delete form;
	}
};

class inteForm : public formual
{
private:
	formual* upper;
	formual* lower;
	formual* expr;
	
public:
	int getType() { return inte; }
	inteForm(formual* upper=nullptr, formual* lower=nullptr, formual* expr=nullptr) : 
		upper(upper), lower(lower), expr(expr) {}
	//这里应该加一个积分/求和积符号的flag
	void draw();
	~inteForm()
	{
		delete upper;
		delete lower;
		delete expr;
	}
};

class fracForm : public formual
{
private:
	formual* numForm;
	formual* denForm;
	
public:
	int getType() { return frac; }
	fracForm(formual* numForm, formual* denForm) : numForm(numForm), denForm(denForm) {}
	void draw();
	~fracForm()
	{
		delete numForm;
		delete denForm;
	}
};

class matForm : public matForm
{
private:
	list<list<formual*>> allForm;

public:
	int getType() { return mat; }
	matForm(list<list<formual*>> allForm) : allForm(allForm) {}
	void draw();
	~matForm()
	{
		for(auto i : allForm)
		{
			for(formual* j : i)
				delete j;
		}
	}
};
