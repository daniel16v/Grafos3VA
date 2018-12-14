class Vertice implements Comparable<Vertice>
{
    public final String name;
    public Aresta [] adjacencias;
    public double minDistance = Double.POSITIVE_INFINITY;
    public Vertice anterior;
    public Vertice(String argName) { name = argName; }
    public String toString() { return name; }
    public int compareTo(Vertice other)
    {
        return Double.compare(minDistance, other.minDistance);
    }

}
