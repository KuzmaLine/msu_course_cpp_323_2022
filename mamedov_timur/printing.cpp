#include "printing.hpp"
#include <sstream>
#include <string>
#include "graph.hpp"

namespace printing {
namespace json {
std::string print_vertex(const Graph::Vertex& vertex, const Graph& graph) {
  std::stringstream json_string;
  json_string << "\n\t\t{ \"id\":" << vertex.id() << ", \"edges_ids\": [";
  const auto& edge_ids = graph.get_connected_edge_ids(vertex.id());

  if (!edge_ids.empty()) {
    auto it = edge_ids.begin();
    ++it;

    for (; it != edge_ids.end(); ++it) {
      json_string << *std::prev(it) << ", ";
    }
    json_string << *std::prev(it);
  }

  json_string << "] }";

  return json_string.str();
}

std::string print_edge(const Graph::Edge& edge, const Graph& graph) {
  std::stringstream json_string;
  json_string << "\n\t\t{ \"id\": " << edge.id() << ", \"vertex_ids\": ["
              << edge.get_first_vertex_id() << ", "
              << edge.get_second_vertex_id() << "] }";

  return json_string.str();
}

std::string print_graph(const Graph& graph) {
  std::stringstream json_string;
  json_string << "{\n\t\"vertices\": [";
  const auto& vertices = graph.get_vertices();
  const auto& edges = graph.get_edges();

  if (!vertices.empty()) {
    auto it_vertices = vertices.begin();
    auto prev_it_vertices = it_vertices;
    ++it_vertices;

    for (; it_vertices != vertices.end(); ++it_vertices, ++prev_it_vertices) {
      json_string << print_vertex(prev_it_vertices->second, graph) << ",";
    }
    json_string << print_vertex(prev_it_vertices->second, graph);
  }

  json_string << "\n\t],\n\t\"edges\": [";

  if (!edges.empty()) {
    auto it_edges = edges.begin();
    auto prev_it_edges = it_edges;
    ++it_edges;

    for (; it_edges != edges.end(); ++it_edges, ++prev_it_edges) {
      json_string << print_edge(prev_it_edges->second, graph) << ",";
    }
    json_string << print_edge(prev_it_edges->second, graph) << "\n\t]\n}\n";
  }
  return json_string.str();
}
}  // namespace json
}  // namespace printing
