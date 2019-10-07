class baseForm
{
	constructor()
	{
		this.x1=-1;
		this.y1=-1;
		this.fontSize=-1;
		this.supMaker=null;
		this.subMaker=null;
	}
	
	verify()
	{
		return this.x1!=-1 && this.y1!=-1 && this.fontSize!=-1;
	}
}

class maker
{
	constructor(markFlag, form)
	{
		this.markFlag=markFlag;
		this.form=markFlag;
	}
	
	draw()
	{
		//fix:根据上下标计算form的三个量
		form.draw();
	}
}

class formual extends baseForm
{
	constructor(formStr)
	{
		super();
		this.formStr=formStr;
	}
	
	getType()
	{ return "basic"; }
	
	draw()
	{
		//fix:
	}
}

class sqrtForm extends baseForm
{
	constructor(form)
	{
		super();
		this.form=form;
	}
	
	getType()
	{ return "sqrt"; }
	
	draw()
	{
		//fix:
	}
}

class inteForm extends baseForm
{
	constructor(upper=null, lower=null, expr=null)
	{
		super();
		this.upper=upper;
		this.lower=lower;
		this.expr=expr;
	}
	
	getType()
	{ return "inte"; }
	
	draw()
	{
		//fix:
	}
}

class fracForm extends baseForm
{
	constructor(numForm, denForm)
	{
		super();
		this.numForm=numForm;
		this.denForm=denForm;
	}
	
	getType()
	{ return "frac"; }
	
	draw()
	{
		//fix:
	}
}

class matForm extends baseForm
{
	constructor(allForm)
	{
		super();
		this.allForm=allForm;
	}
	
	getType()
	{ return "mat"; }
	
	draw()
	{
		//fix:
	}
}
