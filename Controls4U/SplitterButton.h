// SPDX-License-Identifier: Apache-2.0
// Copyright 2021 - 2022, the Anboto author and contributors
#ifndef _Controls4U_SplitterButton_h_
#define _Controls4U_SplitterButton_h_


namespace Upp {
	
class SplitterButton : public StaticRect {
public:
	typedef SplitterButton CLASSNAME;

	SplitterButton();
	virtual ~SplitterButton() {};
	
	SplitterButton& Horz(Ctrl &left, Ctrl &right);
	SplitterButton& Vert(Ctrl& top, Ctrl& bottom);
	
	SplitterButton &SetPositions(const Vector<int> &_positions);
	SplitterButton &SetPositions(int pos1);
	SplitterButton &SetPositions(int pos1, int pos2);
	SplitterButton &SetPositions(int pos1, int pos2, int pos3);
	const Vector<int> &GetPositions() const {return positions;}
	
	int GetPos()							{return splitter.GetPos();}
	
	SplitterButton &SetInitialPositionId(int id);
	
	SplitterButton &SetButtonNumber(int _buttonNumber) {
		ASSERT(_buttonNumber > 0 && _buttonNumber <= 2);
		buttonNumber = _buttonNumber;
		button2.Show(buttonNumber > 1);
		return *this;
	}
		
	SplitterButton &SetButtonWidth(int width) {buttonWidth = width; return *this;}
	void SetButton(int id);
	
private:
	bool movingRight;		
	int buttonWidth;
	Vector<int> positions;
	int positionId;
	int buttonNumber;
	
	struct SplitterLay : Splitter {
		Callback1<int> WhenLayout;
		
		virtual void Layout() {
			Splitter::Layout();
			WhenLayout(PosToClient(GetPos()));
		}
	};
	SplitterLay splitter;
	
	Button button1, button2;
	
	void OnLayout(int pos);
	void SetArrows();
};
/*
class BoxOld : public Splitter {
public:
	typedef BoxOld CLASSNAME;

	BoxOld() : Splitter() {SetStyle(StyleDefault());}

	static const Style& StyleDefault();

private:	
	virtual void   MouseMove(Point , dword ) 	{};
	virtual void   LeftDown(Point , dword ) 	{};
	virtual void   LeftUp(Point , dword ) 		{};
	virtual Image  CursorImage(Point , dword ) {return Null;};	
};
*/
class Box : public StaticRect {
typedef Box CLASSNAME;

public:	
	Box &Add(Ctrl &ctrl, int row, int col) {
		Ctrl::Add(ctrl);

		if (row >= heights.size()) {
			ctrls.SetCount(row+1);
			heights.SetCount(row+1, 1000);
		}
		if (col >= widths.size()) 
			widths.SetCount(col+1, 1000);
		
		for (int r = 0; r < heights.size(); ++r) 
			ctrls[r].SetCount(widths.size(), nullptr);

		ctrls[row][col] = &ctrl;
		
		Layout();
		Refresh();
		
		return *this;
	}
	
	void Clear() {
		ctrls.Clear();
		widths.Clear();
		heights.Clear();
		
		Layout();
		Refresh();
	}
	
	int GetRows() {return heights.size();}
	int GetCols() {return widths.size();}
	
	Box &SetWidths(const Vector<int> &t) {
		widths = clone(t);
		Layout();
		Refresh();
	    return *this;
	}
	
	Box &SetWidth(int id, int width) {
		widths[id] = width;
		Layout();
		Refresh();
	    return *this;
	}
	
	Box &SetHeights(const Vector<int> &t) {
		heights = clone(t);
		Layout();
		Refresh();
	    return *this;
	}
	
	Box &SetHeight(int id, int height) {
		heights[id] = height;
		Layout();
		Refresh();
	    return *this;
	}
	
	Function<void(int width, int height, Vector<int> &widths)> WhenWidths;
	Function<void(int width, int height, Vector<int> &heights)> WhenHeights;

private:
	Array<Array<Ctrl *>> ctrls;
	Vector<int> widths;
	Vector<int> heights;

	virtual void Layout() {
		if (widths.size() == 0 || heights.size() == 0)
			return;
		
		int horiz = GetSize().cx;
		int vert = GetSize().cy;
		
		if (WhenWidths)
			WhenWidths(horiz, vert, widths);
			
		int width = 0;
		for (int c = 0; c < widths.size(); ++c)
			width += widths[c];
		double widthratio = double(horiz)/width;
		
		if (WhenHeights)
			WhenHeights(horiz, vert, heights);
		
		int height = 0;
		for (int r = 0; r < heights.size(); ++r)
			height += heights[r];
		double heightratio = double(vert)/height;
		
		double heightacc = 0;
		for (int r = 0; r < heights.size(); ++r) {
			double hh = heights[r]*heightratio;
			double widthacc = 0;
			for (int c = 0; c < widths.size(); ++c) {
				double ww = widths[c]*widthratio;
				if (ctrls[r][c]) 
					ctrls[r][c]->TopPos(int(heightacc), int(hh)).LeftPos(int(widthacc), int(ww));
				widthacc += ww;
			}
			heightacc += hh;
		}
	}
};

}

#endif
