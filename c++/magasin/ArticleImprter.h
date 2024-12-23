#include"Article.h"


class ArticleImporter : public Article{
private:
    double Tax;
public:
    ArticleImporter(int,string,double,double);
    ~ArticleImporter();
    void afficher();
};
