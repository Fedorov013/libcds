//$$CDS-header$$

#include "tree/hdr_ellenbintree_set.h"
#include <cds/container/ellen_bintree_set_hp.h>

#include "tree/hdr_intrusive_ellen_bintree_pool_hp.h"
#include "unit/print_ellenbintree_stat.h"

namespace tree {
    namespace cc = cds::container;
    namespace co = cds::opt;
    namespace {
        typedef cds::gc::HP     gc_type;

        typedef cc::ellen_bintree::node<gc_type, EllenBinTreeSetHdrTest::value_type>                    tree_leaf_node;
        typedef cc::ellen_bintree::internal_node< EllenBinTreeSetHdrTest::key_type, tree_leaf_node >    tree_internal_node;
        typedef cc::ellen_bintree::update_desc<tree_leaf_node, tree_internal_node>                      tree_update_desc;

        struct print_stat {
            template <typename Tree>
            void operator()( Tree const& t)
            {
                std::cout << t.statistics();
            }
        };
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_less()
    {
        struct set_traits : public cc::ellen_bintree::traits{
            typedef EllenBinTreeSetHdrTest::key_extractor key_extractor;
            typedef EllenBinTreeSetHdrTest::less less;
        };
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type, set_traits > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_cmp()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::compare< compare >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_cmpless()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::compare< compare >
                ,co::less< less >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_less_ic()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::less< less >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_cmp_ic()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::item_counter< cds::atomicity::item_counter >
                ,co::compare< compare >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_less_stat()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::less< less >
                ,co::stat< cc::ellen_bintree::stat<> >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_cmp_ic_stat()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::item_counter< cds::atomicity::item_counter >
                ,co::stat< cc::ellen_bintree::stat<> >
                ,co::compare< compare >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_less_pool()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::less< less >
                ,co::node_allocator< cds::memory::pool_allocator< tree_internal_node, ellen_bintree_hp::internal_node_pool_accessor > >
                ,cc::ellen_bintree::update_desc_allocator< cds::memory::pool_allocator< tree_update_desc, ellen_bintree_hp::update_desc_pool_accessor > >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

    void EllenBinTreeSetHdrTest::EllenBinTree_hp_less_pool_ic_stat()
    {
        typedef cc::EllenBinTreeSet< gc_type, key_type, value_type,
            cc::ellen_bintree::make_set_traits<
                cc::ellen_bintree::key_extractor< key_extractor >
                ,co::less< less >
                ,co::node_allocator< cds::memory::pool_allocator< tree_internal_node, ellen_bintree_hp::internal_node_pool_accessor > >
                ,cc::ellen_bintree::update_desc_allocator< cds::memory::pool_allocator< tree_update_desc, ellen_bintree_hp::update_desc_pool_accessor > >
                ,co::item_counter< cds::atomicity::item_counter >
                ,co::stat< cc::ellen_bintree::stat<> >
            >::type
        > set_type;

        test<set_type, print_stat>();
    }

} // namespace tree
