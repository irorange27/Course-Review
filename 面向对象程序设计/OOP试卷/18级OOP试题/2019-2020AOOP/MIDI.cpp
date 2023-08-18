// MIDI.cpp
#include "MIDI.h"

HMIDIOUT MIDI::hMIDI;			// ��̬���ݳ�Ա���壨MIDI�豸�����
int MIDI::NumObjs = 0;			// ��̬���ݳ�Ա���壨����ĸ�����

DWORD MIDI::MidiOutMessage(int iStatus, int iChannel, int iFlip,  int iVolume)
{
	DWORD dwMessage = (iVolume << 16) | (iFlip << 8) | iStatus         | iChannel;
					//      ����      |     ����     | ״̬�ֽ�(��4λ) | ͨ��(��4λ)
	return midiOutShortMsg (hMIDI, dwMessage) ;
}

MIDI::MIDI(const string &Name, int n, const Music *data) : name(Name), len(n)
{
	if(++NumObjs==1)		// ���ǵ�һ���������MIDI�豸
		midiOutOpen(&hMIDI, 0, 0, 0, CALLBACK_NULL);
	if(len<0) len = 0;
	if(data==NULL) return;
	for(int i=0; i<len; i++)
		x[i] = data[i];
}

MIDI::MIDI(const MIDI &m) : name(m.name), len(m.len)	// �������캯��
{
	++NumObjs;
	for(int i=0; i<len; i++)
		x[i] = m.x[i];
}

MIDI::~MIDI()
{
	if(--NumObjs==0)		// �������һ��������ر�MIDI�豸
		midiOutClose(hMIDI);
}

void MIDI::Play() const
{
	cout << name << endl;
	for(int i=0; i<len; i++)
	{
		cout << x[i].note << " ";
		MidiOutMessage(0x90, 0x00, x[i].note, x[i].volume);	// ����
		Sleep(x[i].deltaTime*60000/180);					// ÿ����180��
		MidiOutMessage(0x80, 0x00, x[i].note, 127);			// ����
	}
	cout << endl;
}

MIDI_Piano::MIDI_Piano(const string &Name, int n, const Music *data)
	: MIDI(Name, n, data), timbre(0)
{
}

void MIDI_Piano::Play() const
{
	cout << "��������\t";					// �˴��޻���
	MidiOutMessage(0xC0, 0x00, timbre, 0);	// ������ɫ
	MIDI::Play();
}

MIDI_Violin::MIDI_Violin(const string &Name, int n, const Music *data)
	: MIDI(Name, n, data), timbre(40)
{
}

void MIDI_Violin::Play() const
{
	cout << "С��������\t";					// �˴��޻���
	MidiOutMessage(0xC0, 0x00, timbre, 0);	// ������ɫ
	MIDI::Play();
}

MIDI_ChurchOrgan::MIDI_ChurchOrgan(const string &Name, int n, const Music *data)
	: MIDI(Name, n, data), timbre(19)
{
}

void MIDI_ChurchOrgan::Play() const
{
	cout << "���ùܷ�������\t";				// �˴��޻���
	MidiOutMessage(0xC0, 0x00, timbre, 0);	// ������ɫ
	MIDI::Play();
}
