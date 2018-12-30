////
//// Created by Rabia on 30/12/2018.
////
//
//#ifndef DNA_ANALYZER_MULTIINDEXMAP_H
//#define DNA_ANALYZER_MULTIINDEXMAP_H
//
//#include <map>
//
//template<typename T, typename U, typename V>
//class MultiIndexMap
//{
//public:
//
//    bool insert (T primary, U secondary, std::shared_ptr<V> data);
//
//    std::shared_ptr<V> findByPrimary (T primary);
//
//    std::shared_ptr<V> findBySecondary (U secondary);
//
//private:
//
//    typedef std::map<T, std::shared_ptr<V> > PrimaryType;
//    typedef std::map<U, std::shared_ptr<V> > SecondaryType;
//
//    PrimaryType m_primary;
//    SecondaryType m_secondary;
//
//};
//
//
//template<typename T, typename U, typename V>
//bool MultiIndexMap<T, U, V>::
//insert (T primary, U secondary, std::shared_ptr<V> data)
//{
//    m_primary.insert (std::pair<T, std::shared_ptr<V> > (primary, data));
//    m_secondary.insert (std::pair<U, std::shared_ptr<V> > (secondary, data));
//}
//
//
//template<typename T, typename U, typename V>
//std::shared_ptr<V> MultiIndexMap<T, U, V>::
//findByPrimary (T key)
//{
//    if (m_primary.find (key) != m_primary.end ())
//        return m_primary[key];
//}
//
//
//template<typename T, typename U, typename V>
//std::shared_ptr<V> MultiIndexMap<T, U, V>::
//findBySecondary (U key)
//{
//    if (m_secondary.find (key) != m_secondary.end ())
//        return m_secondary[key];
//}
//#endif //DNA_ANALYZER_MULTIINDEXMAP_H
