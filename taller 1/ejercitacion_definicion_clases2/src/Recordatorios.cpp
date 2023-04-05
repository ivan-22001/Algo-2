#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    // Completar declaraciones funciones
    Fecha(int mes, int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();
    void incrementar_mes();

  private:
    int m_;
    int d_;
    //Completar miembros internos
};

Fecha::Fecha(int mes, int dia): m_(),d_() {
    m_ = mes;
    d_ = dia;
}
int Fecha::mes() {
    return m_;
}
int Fecha::dia() {
    return d_;
}
ostream& operator<<(ostream& os, Fecha f) {
    os <<  f.dia() << "/" << f.mes();
    return os;
}
#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();

    // Completar iguadad (ej 9)
    return (igual_dia && igual_mes);
}
#endif
void Fecha::incrementar_dia() {
    if(m_== 4 || m_==6 || m_==9 || m_==11){
        if(d_==30){
            incrementar_mes();
            d_ = 1;
        }
        else
            d_++;
    }
    else if(m_ == 2){
        if(d_==28){
            incrementar_mes();
            d_ = 1;
        }
        else
            d_++;
    }
    else{
        if(d_ < 31)
            d_++;
        else{
            incrementar_mes();
            d_ = 1;
        }
    }
}
void Fecha::incrementar_mes() {
    if(m_<12)
        m_++;
    else
        m_ = 1;
}
// Ejercicio 11, 12

// Clase Horario
class Horario{
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator<(Horario h);

    private:
        int h_;
        int m_;
};
Horario::Horario(uint hora, uint min): h_(),m_() {
    h_ = hora;
    m_ = min;
}
uint Horario::hora() {
    return h_;
}
uint Horario::min() {
    return m_;
}
ostream& operator<<(ostream& os, Horario h) {
    os <<  h.hora() << ":" << h.min();
    return os;
}
bool Horario::operator<(Horario h) {
    if(this->hora() < h.hora())
        return true;
    else if(this->hora() == h.hora()){
        if(this->min() < h.min())
            return true;
        else
            return false;
    }
    else
        return false;
}
// Ejercicio 13

// Clase Recordatorio
class Recordatorio{
public:
    Recordatorio(Fecha f, Horario h,string mensaje);
    string mensaje();
    Fecha fecha();
    Horario horario();
private:
    string m_;
    Fecha f_;
    Horario h_;

};
Recordatorio::Recordatorio(Fecha f, Horario h,string mensaje) : m_(),f_(fecha().dia(),fecha().mes()),h_(horario().hora(),horario().min()){
    m_ = mensaje;
    f_ = f;
    h_ = h;

}
string Recordatorio::mensaje() {
    return m_;
}
Fecha Recordatorio::fecha() {
    return f_;
}
Horario Recordatorio::horario() {
    return h_;
}
ostream& operator<<(ostream& os, Recordatorio r) {
    os <<  r.mensaje() << " @ " << r.fecha() << " " << r.horario() ;
    return os;
}
// Ejercicio 14
class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
private:
    Fecha h_;
    list<Recordatorio> r_h_;
};
Agenda::Agenda(Fecha fecha_inicial) : h_(hoy().dia(),hoy().mes()),r_h_(){
    h_ = fecha_inicial;
}
void Agenda::agregar_recordatorio(Recordatorio rec) {
    r_h_.push_back(rec);
}
void Agenda::incrementar_dia() {
    return h_.incrementar_dia();
}
list<Recordatorio> Agenda::recordatorios_de_hoy() {
    vector<Recordatorio> rec;
    list<Recordatorio> rec_Hoy;
    for(Recordatorio r : r_h_){
        if(h_ == r.fecha())
            rec.push_back(r);
    }
    for(int i = 0; i < rec.size(); i++){
        for(int j = i+1; j < rec.size(); j++){
            if(rec[i].horario().hora() > rec[j].horario().hora()){
                Recordatorio temp = rec[i];
                rec[i] = rec[j];
                rec[j] = temp;
            }
            else if(rec[i].horario().hora() == rec[j].horario().hora()){
                if(rec[i].horario().min() > rec[j].horario().min())
                {
                    Recordatorio temp = rec[i];
                    rec[i] = rec[j];
                    rec[j] = temp;
                }
            }
        }
    }
    for(Recordatorio r : rec){
        rec_Hoy.push_back(r);
    }
    return rec_Hoy;
}
Fecha Agenda::hoy() {
    return h_;
}
// Clase Agenda
ostream& operator<<(ostream& os, Agenda a) {
    os <<  a.hoy() << endl;
    os << "=====" << endl;
    for(Recordatorio r : a.recordatorios_de_hoy()){
        os <<  r.mensaje() << " @ " << r.fecha() << " " << r.horario() << endl ;

    }
    return os;
}
