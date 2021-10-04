#include "AND3.h"

AND3::AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gates(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	GraphicsInfo GInfo;
	GInfo = this->m_GfxInfo;
	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++) {
		m_InputPins[i].setComponent(this);
		m_InputPins[i].setConnected(false);

		GInfo.y1 = this->m_GfxInfo.y1 + 10 * (i + 1);
		m_InputPins[i].SetGfxInfo(GInfo);
	}
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	m_OutputPin = HIGH;
	for (int j = 0; j < 3; j++)
	{
		if (m_InputPins[j].getStatus() == LOW)  m_OutputPin = LOW;
	} 
}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (select == false) {
		pOut->DrawAND3(m_GfxInfo);
	}
	else {
		pOut->DrawAND3(m_GfxInfo, true);
	}
	pOut->reDrawLabel(m_GfxInfo, GetLabel());

}

void AND3::save(ofstream *outputFile) {
	int idNum = id;
	string label = GetLabel();
	int x1 = m_GfxInfo.x1;
	int x2 = m_GfxInfo.x2;
	int y1 = m_GfxInfo.y1;
	int y2 = m_GfxInfo.y2;

	*outputFile << "And3" << "\t" << idNum << "\t" << label << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << endl;
}


//returns status of outputpin
int AND3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int m)	
{
	return m_InputPins[m-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int z, STATUS d)
{
	m_InputPins[z-1].setStatus(d);
}
