#ifndef APPLICATION_H
#define APPLICATION_H
#include <QMap>
#include <QPair>
#include <QVector>
#include <QString>

struct WordStructure
{
	QPair<QString, QString> words;
	int repetitions;
};

class Application
{
public:
	static inline Application* getInstance()
	{
		if(!m_Application)
		{
			m_Application = new Application();
		}
		return m_Application;
	}
	inline QVector<WordStructure> getWords() {return m_Words;}
	void addWord(WordStructure wordsturct);
private:
	Application();
	static Application* m_Application;
	QVector<WordStructure> m_Words;
};

#endif // APPLICATION_H
