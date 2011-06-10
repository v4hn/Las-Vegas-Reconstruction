#ifndef __HALF_EDGE_H__
#define __HALF_EDGE_H__

namespace lssr
{

/**
 * @brief An edge representation in a half edge mesh.
 */
template<typename HVertexT, typename FaceT>
class HalfEdge{
public:

    /**
     * @brief   Ctor.
     */
	HalfEdge() : start(0), end(0), pair(0), next(0), face(0), used(false) {};

	/**
	 * @brief   Dtor.
	 */
	~HalfEdge()
	{
		delete next;
		delete pair;
	}

	/// A pointer to the next edge in current contour
	HalfEdge<HVertexT, FaceT>* next;

	/// A pointer to the pair edge of this edge
	HalfEdge<HVertexT, FaceT>* pair;

	/// A pointer to the start vertex of this edge
	HVertexT* start;

	/// A pointer to the end vertex of this edge
	HVertexT* end;

	/// A pointer to the surrounded face
	FaceT* face;

	/// Used for clustering (may be removed soon)
	bool used;
};

} // namespace lssr

#endif