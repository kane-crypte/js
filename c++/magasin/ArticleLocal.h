#include"Article.h"


class ArticleLocal : public Article{
private:
    double coux;
public:
    ArticleLocal(int,string,double,double);
    ~ArticleLocal();
    void afficher();
};
