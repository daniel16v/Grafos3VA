import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Dijkstra{
    public static void calcularCaminhos(Vertice fonte)
    {
        fonte.minDistance = 0.;
        PriorityQueue<Vertice> VerticeQueue = new PriorityQueue<Vertice>();
    VerticeQueue.add(fonte);
    
    //Enquanto a fila de Vertice não está vazia
    while (!VerticeQueue.isEmpty()) {
        Vertice u = VerticeQueue.poll();
            //Visitando cada extremidade saindo de você
        for (Aresta e : u.adjacencias){
                Vertice v = e.alvo;
                double peso = e.peso;
                double atravesDaDistancia = u.minDistance + peso;
                if (atravesDaDistancia < v.minDistance) {
                	VerticeQueue.remove(v);

                	v.minDistance = atravesDaDistancia ;
                	v.anterior = u;
                	VerticeQueue.add(v);
                }
            }
        }
    }

    public static List<Vertice> getCaminhoMaisCurtoPara(Vertice alvo)
    {
        List<Vertice> caminho = new ArrayList<Vertice>();
        for (Vertice Vertice = alvo; Vertice != null; Vertice = Vertice.anterior)
        	caminho.add(Vertice);

        Collections.reverse(caminho);
        return caminho;
    }

    public static void main(String[] args)
    {
        // Marcando todos os vértices
        Vertice Anapolis = new Vertice("Anapolis");
        Vertice Neropolis = new Vertice("Neropolis");
        Vertice Goiania = new Vertice("Goiania");
        Vertice BelaVista = new Vertice("Bela Vista");
        Vertice Morrinhos = new Vertice("Morrinhos");
        Vertice Catalao = new Vertice("Catalao");
        Vertice Uberlandia = new Vertice("UberlAndia");
        Vertice SaoJosedoRioPreto = new Vertice("Sao Jose do Rio Preto");
        Vertice Uberaba = new Vertice("Uberaba");
        Vertice RibeiraoPreto = new Vertice("Ribeirao Preto");
        Vertice SaoCarlos = new Vertice("Sao Carlos");
        Vertice Bauru = new Vertice("Bauru");
        Vertice Botucatu = new Vertice("(Botucatu");
        Vertice Campinas = new Vertice("Campinas");
        Vertice Sorocaba = new Vertice("Sorocaba");
        Vertice SaoPaulo = new Vertice("Sao Paulo");

        // Definindo as arestas e peso
      
        Anapolis.adjacencias = new Aresta[]{ new Aresta(Neropolis, 33) };
        Anapolis.adjacencias = new Aresta[]{ new Aresta(Goiania, 59) };
        Neropolis.adjacencias = new Aresta[]{ new Aresta(Goiania, 36) };
        Goiania.adjacencias = new Aresta[]{ new Aresta(BelaVista, 54) };
        Goiania.adjacencias = new Aresta[]{ new Aresta(Morrinhos, 132) };        
        BelaVista.adjacencias = new Aresta[]{ new Aresta(Morrinhos, 98) };
        Morrinhos.adjacencias = new Aresta[]{ new Aresta(Catalao, 176) };
        Morrinhos.adjacencias = new Aresta[]{ new Aresta(Uberlandia, 216) };
        Uberlandia.adjacencias = new Aresta[]{ new Aresta(SaoJosedoRioPreto, 289) };        
        Catalao.adjacencias = new Aresta[]{ new Aresta(Uberlandia, 109) };         
        Uberlandia.adjacencias = new Aresta[]{ new Aresta(Uberaba, 109) };
        Uberaba.adjacencias = new Aresta[]{ new Aresta(RibeiraoPreto, 173) };
        SaoJosedoRioPreto.adjacencias = new Aresta[]{ new Aresta(SaoCarlos, 206) };
        RibeiraoPreto.adjacencias = new Aresta[]{ new Aresta(SaoCarlos, 104) };
        SaoCarlos.adjacencias = new Aresta[]{ new Aresta(Bauru, 156) };
        SaoCarlos.adjacencias = new Aresta[]{ new Aresta(Campinas, 144) };
        Bauru.adjacencias = new Aresta[]{ new Aresta(Botucatu, 96) };
        Botucatu.adjacencias = new Aresta[]{ new Aresta(Sorocaba, 174) };
        Campinas.adjacencias = new Aresta[]{ new Aresta(Sorocaba, 85) };
        Sorocaba.adjacencias = new Aresta[]{ new Aresta(SaoPaulo, 112) };
        SaoPaulo.adjacencias = new Aresta[]{ new Aresta(SaoPaulo, 112) };
              
        calcularCaminhos(Anapolis); // Executar Dijkstra
        System.out.println("A distancia de Anápolis até " + SaoPaulo + " é: " + SaoPaulo.minDistance);
        List<Vertice> caminho = getCaminhoMaisCurtoPara(SaoPaulo);
        System.out.println("A melhor rota é: " + caminho);
    }
}