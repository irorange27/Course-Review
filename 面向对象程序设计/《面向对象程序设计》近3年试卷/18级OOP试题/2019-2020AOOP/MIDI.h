// MIDI.h	��������Ҫ���Ӷ�ý���libwinmm.a
// ���÷��� Project/Settings.../Link/Libraries���ֵΪC:\MinGWStudio\MinGW\lib\libwinmm.a
#ifndef MIDI_H
#define MIDI_H
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

const int N = 100;

struct Music
{
	int deltaTime, note, volume;	// ʱ����������������������
};

class MIDI		// �������ֻ��ӿ�(Musical Instrument Digital Interface)
{
public:
	MIDI(const string &Name="", int n=0, const Music *data=NULL);// ���캯��
	MIDI(const MIDI &m);		// �������캯��
	virtual ~MIDI();			// �����������麯����
	virtual void Play() const;	// �����������麯����
protected:
	static DWORD MidiOutMessage(int iStatus, int iChannel, int iFlip, int iVolume);
			// ��MIDI�豸������Ϣ������������ɫ������������ֹͣ�����ȹ���
	static HMIDIOUT hMIDI;		// ��̬���ݳ�Ա
	static int NumObjs;			// ��������ĸ���
	string name;				// ������
	int len;					// ��������������������N��
	Music x[N];					// ����
};

class MIDI_Piano : public MIDI	// ������
{
public:
	MIDI_Piano(const string &Name="", int n=0, const Music *data=NULL);
	void Play() const;
protected:
	int timbre;					// ��ɫ����Ӧĳ�������� 
};

class MIDI_Violin : public MIDI	// С������
{
public:
	MIDI_Violin(const string &Name="", int n=0, const Music *data=NULL);
	void Play() const;
protected:
	int timbre;					// ��ɫ����Ӧĳ��������
};

class MIDI_ChurchOrgan : public MIDI	// ���ùܷ�����
{
public:
	MIDI_ChurchOrgan(const string &Name="", int n=0, const Music *data=NULL);
	void Play() const;
protected:
	int timbre;					// ��ɫ����Ӧĳ�������� 
};

#endif
