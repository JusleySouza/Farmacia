#include <iostream>
#include <string>
#include <map>
using namespace std;

class Medicamentos
{
    public:
        string nome, validade, aquisicao;
        int codigo, lote, quantidade;
        float valor;
    public:
        void cadastrarMedicamento(void);
        void exibirDados(void);
};

class Clientes
{
    public:
        string nome, endereco, nascimento, cpf, telefone, codigo; 
    public:
        void cadastrarCliente(void);
        void exibirDados(void);
};

class Fornecedores
{
    public:
        string nome, codigo, telefone, email, empresa, cnpj;
    public:
        void cadastrarFornecedor(void);
        void exibirDados(void);
};

class ListaMedicamentos
{
    public:
        map <int, Medicamentos> listaMedicamentos;
    public:
        void adicionarMedicamento(Medicamentos medicamento);
        Medicamentos exibirMedicamento(int codigoMedicamento);
};

class Vendas
{
    private:
        string codigoCliente, codigoVenda;
        int quantidade, codigoMedicamento;
        float valorTotal;
    public:
        void cadastrarVenda(ListaMedicamentos listaMedicamentos );
        void finalizarVenda(void);
};

int main()
{
    Medicamentos medicamento;
    Clientes cliente;
    Fornecedores fornecedor;
    ListaMedicamentos listaMedicamentos;
    Vendas vendas;
    
    int opcao;
    do
    {
        cout <<"\n 1- Cadastrar Medicamento: ";
        cout <<"\n 2- Cadastrar Cliente: ";
        cout <<"\n 3- Cadastrar Fornecedor: ";
        cout <<"\n 4- Cadastrar Vendas: ";
        cout <<"\n 5- Sair do programa: ";
        cout <<"\n Escolha uma das opcoes acima: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            medicamento.cadastrarMedicamento();
            listaMedicamentos.adicionarMedicamento(medicamento);
            medicamento.exibirDados();
            break;
        case 2:
            cliente.cadastrarCliente();
            cliente.exibirDados();
            break;
        case 3:
            fornecedor.cadastrarFornecedor();
            fornecedor.exibirDados();
            break;
        case 4:
            vendas.cadastrarVenda(listaMedicamentos);
            vendas.finalizarVenda(); 
            break;
        case 5:
            cout <<"\n Encerrando o programa.. Tenha um bom dia!!\n";
            return 0;
        default: 
            cout <<"\n Escolha uma opcao valida!!\n ";
            break;
        }
    } while (true);
}

void Medicamentos::cadastrarMedicamento(void)
{
    cout <<"\n Digite o nome do Medicamento: ";
    cin >> nome;
    cout <<"\n Digite o codigo do Medicamento: ";
    cin >> codigo;
    cout <<"\n Digite a data de validade do Medicamento: ";
    cin >> validade;
    cout <<"\n Digite o lote do Medicamento: ";
    cin >> lote;
    cout <<"\n Digite a data de aquisicao do Medicamento: ";
    cin >> aquisicao;
    cout <<"\n Digite a quantidade de Medicamento: ";
    cin >> quantidade;
    cout <<"\n Digite o valor do Medicamento: ";
    cin >> valor;
    cout <<"\n Medicamento cadastrado com sucesso!!!\n ";
}

void Medicamentos::exibirDados(void)
{
    cout <<"\nCodigo do medicamento: "<<codigo<<endl;
    cout <<"Nome do medicamento: "<<nome<<endl;
    cout <<"Data de validade: " <<validade<<endl;
    cout <<"Lote do medicamento: "<<lote<<endl;
    cout <<"Data de Aquisicao: "<<aquisicao<<endl;
    cout <<"Quantidade de Medicamentos: "<<quantidade<<endl;
    cout <<"Valor do Medicamento: "<<valor<<endl;
    cout <<"_______________________________________________________\n ";
}

void Clientes::cadastrarCliente(void)
{
    cout <<"\n Digite o nome do Cliente: ";
    cin.ignore();
    getline(cin, nome);
    cout <<"\n Digite o codigo do Cliente: ";
    cin >> codigo;
    cout <<"\n Digite o CPF do Cliente: ";
    cin >> cpf;
    cout <<"\n Digite o telefone para contato: ";
    cin >> telefone;
    cout <<"\n Digite o endereco do Cliente: ";
    cin.ignore();
    getline(cin, endereco);
    cout <<"\n Digite a data de nascimento do Cliente: ";
    cin >> nascimento;
    cout <<"\n Cliente cadastrado com sucesso!!!\n ";
}

void Clientes::exibirDados(void)
{
    cout <<"\n Codigo do Cliente: "<<codigo<<endl;
    cout <<" Nome do Cliente: "<<nome<<endl;
    cout <<" CPF do Cliente: "<<cpf<<endl;
    cout <<" Data de Nascimento: "<<nascimento<<endl;
    cout <<" Telefone para contato: "<<telefone<<endl;
    cout <<" Endereco do Cliente: "<<endereco<<endl;
    cout <<"_________________________________________________________\n ";
}

void Fornecedores::cadastrarFornecedor(void)
{
    cout <<"\n Digite o nome do Fornecedor: ";
    cin.ignore();
    getline(cin, nome);
    cout <<"\n Digite o codigo do fornecedor: ";
    cin >> codigo;
    cout <<"\n Digite o telefone do Fornecedor: ";
    cin >> telefone;
    cout <<"\n Digite a empresa fornecedora: ";
    cin.ignore();
    getline(cin, empresa);
    cout <<"\n Digite o e-mail da empresa: ";
    cin.ignore();
    getline(cin, email);
    cout <<"\n Digite o CNPJ da empresa: ";
    cin >> cnpj;
    cout <<"\n Fornecedor cadastrado com sucesso!!!\n ";
}

void Fornecedores::exibirDados(void)
{
    cout <<"\n Codigo do Fornecedor: "<<codigo<<endl;
    cout <<" Nome do Fornecedor: "<<nome<<endl;
    cout <<" Telefone para Contato: "<<telefone<<endl;
    cout <<" Nome da Empresa: "<<empresa<<endl;
    cout <<" Email da Empresa: "<<email<<endl;
    cout <<" CNPJ da Empresa: "<<cnpj<<endl;
    cout <<"________________________________________________________\n ";
    }

void ListaMedicamentos::adicionarMedicamento(Medicamentos medicamento)
{
    listaMedicamentos[medicamento.codigo] = medicamento;
}

Medicamentos ListaMedicamentos::exibirMedicamento(int codigoMedicamento)
{
    return listaMedicamentos[codigoMedicamento];
}

void Vendas::cadastrarVenda(ListaMedicamentos listaMedicamentos)
{
    cout <<"\n Digite o codigo da Venda: ";
    cin >>codigoVenda;
    cout <<"\n Digite o codigo do cliente: ";
    cin >>codigoCliente;
    cout <<"\n Digite o codigo do medicamento: ";
    cin >>codigoMedicamento;
    cout <<"\n Digite a quantidade: ";
    cin >>quantidade;
    valorTotal= quantidade*listaMedicamentos.exibirMedicamento(codigoMedicamento).valor;
    cout <<"\n Venda cadastrada com sucesso!!!\n ";
}

void Vendas::finalizarVenda(void)
{
    cout <<"\n Codigo da venda: "<<codigoVenda<<endl;
    cout <<" Codigo do Cliente: "<<codigoCliente<<endl;
    cout <<" Codigo do Medicamento: "<<codigoMedicamento<<endl;
    cout <<" Quantidade: "<<quantidade<<endl;
    cout <<" Valor Total: "<<valorTotal<<endl;
    cout <<"____________________________________________________________\n ";
}