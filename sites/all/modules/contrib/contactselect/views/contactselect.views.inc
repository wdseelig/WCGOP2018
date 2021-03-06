<?php
/*
*			implements hook_views_data
*/
/*
function contactselect_views_data() {
				watchdog('contactselect','Made it into the hook_views_data routine');
				watchdog('contactselect_views_inc','Made it into the cwt views_data routine');
					$data=array();
					$data['taxonomy_term_data']['table']['join']['crm_core_contacts'] = array(
  					'left_table' => 'field_data_field_tagswithhs',
  					'left_field' => 'field_tagswithhs_tid',
 						'field' => 'tid',
					);
					$data['field_data_field_tagswithhs']['table']['group'] = t('ContactTags');
					$data['field_data_field_tagswithhs']['table']['join']['crm_core_contacts'] = array(
						'left_field' => 'contact_id',
						'field' => 'entity_id',
						);
/*
					$data['field_data_field_tagswithhs']['entity_id'] = array(
						'title' => 'Term ID',
						'help' => 'The ID of the term',					
						'relationship' => array (
							'base' => 'crm_core_contacts',
							'base field' => 'contact_id',
							'handler' => 'views_handler_relationship',
							'label' => 'Link tagswithhs to a Contact',
							'help' => 'Make it possible to grab all of the Contact info',
							),
					);		
					return $data;
}
*/
/*
function contactselect_views_data() {
					watchdog('ContactSelect','Made it into the ContactQueue definition');
					$data=array();
					$data['tblContactQueue']['table']['group'] = t('ContactSelect');
					$data['tblContactQueue']['table']['join']['crm_core_contact'] = array(
  					'left_field' => 'info_id',
 				 		'field' => 'info_id',
 				 		'type' => 'INNER',
			);
				$data['tblContactQueue']['info_id'] = array(
  			'title' => t('info_id'),
  			'help' => t('The info_id of the contact'),
 		 // Information for displaying the info_id
 			 	'field' => array(
    		'handler' => 'views_handler_field',
    		'click sortable' => TRUE,
  ),
  	// Information for accepting an info_id as an argument
  		'argument' => array(
    	'handler' => 'views_handler_argument',
    	'name field' => 'title', // the field to display in the summary.
    	'numeric' => TRUE,
  ),
  	// Information for accepting an info_id as a filter
  		'filter' => array(
    	'handler' => 'views_handler_filter_numeric',
  ),
  	// Information for sorting on an info_id.
  		'sort' => array(
    	'handler' => 'views_handler_sort',
  ),
);

$data['tblContactQueue']['FirstName'] = array(
  			'title' => t('FirstName'),
  			'help' => t('The First Name of the contact'),
 		 // Information for displaying the info_id
 			 	'field' => array(
    		'handler' => 'views_handler_field',
    		'click sortable' => TRUE,
  ),
  	// Information for accepting an FirstName as an argument
  		'argument' => array(
    	'handler' => 'views_handler_argument',
    	'name field' => 'title', // the field to display in the summary.
    	'numeric' => FALSE,
  ),
  	// Information for accepting an FirstName as a filter
  		'filter' => array(
    	'handler' => 'views_handler_filter_string',
  ),
  	// Information for sorting on a FirstName.
  		'sort' => array(
    	'handler' => 'views_handler_sort',
  ),
);
$data['tblContactQueue']['LastName'] = array(
  			'title' => t('LastName'),
  			'help' => t('The LastName of the contact'),
 		 // Information for displaying the LastName
 			 	'field' => array(
    		'handler' => 'views_handler_field',
    		'click sortable' => TRUE,
  ),
  	// Information for accepting a LastName as an argument
  		'argument' => array(
    	'handler' => 'views_handler_argument',
    	'name field' => 'title', // the field to display in the summary.
    	'numeric' => FALSE,
  ),
  	// Information for accepting an LastName as a filter
  		'filter' => array(
    	'handler' => 'views_handler_filter_string',
  ),
  	// Information for sorting on a LastName.
  		'sort' => array(
    	'handler' => 'views_handler_sort',
  ),
);
					return $data;
}
function contactselect_views_query_alter(&$view, &$query) {
				watchdog('contactselect','Made it into the hook_views_query routine');
				if ($view->name == 'ContactsWithTags'){
				$join = new views_join();
        $join->table = 'field_data_field_tagswithhhsv2';
        $join->field = 'entity_id';
        $join->left_table = 'crm_core_contact';
        $join->left_field = 'contact_id';
        $join->type = 'LEFT';
//        $join->table = 'crm_core_contact';
//        $join->field = 'contact_id';
//        $join->left_table = 'field_data_field_tagswithhsv2';
//        $join->left_field = 'entity_id';
//        $join->type = 'LEFT';
        $view->query->add_relationship('field_data_field_tagswithhhsv2', $join, 'crm_core_contact');
        
        $join=new views_join();
        $join->table = 'taxonomy_term_hierarchy';
        $join->field = 'tid';
        $join->left_table = 'field_data_field_tagswithhhsv2';
        $join->left_field = 'field_tagswithhhsv2_tid';
        $join->type = 'LEFT';
        $view->query->add_relationship('taxonomy_term_hierarchy', $join, 'field_data_fields_tagswithhhsv2');
//        kpr($view);
        $firstsplit = array();
        $secondsplit = array();
        $firstsplit = explode("+",$view->exposed_input['field_tagswithhhsv2_tid'][0]);
				$secondsplit = explode(",",$firstsplit[1]);
				$query->group_operator = 'OR';
				if (!empty($firstsplit) && !empty($secondsplit)) {
				if (empty($secondsplit[0])){
						$firstsplit = explode(",", $firstsplit[0]);
						foreach($firstsplit as $key => $value){
							$query->add_where($key + 1,'taxonomy_term_hierarchy.parent',$value,"=");
						}
				}
				else {
						foreach ($secondsplit as $key => $value){
							$query->add_where($key + 1,'field_data_field_tagswithhhsv2.field_tagswithhhsv2_tid',$value,'=');
						}
				}
			}
			$zz = 1;
			 unset($query->where['1']['conditions']['1']);
//			 kpr($query);
				$view->firstsplit = $firstsplit;
				$view->secondsplit = $secondsplit;


//        $query->add_where(1,'field_data_field_tagswithhs.field_tagswithhs_tid',40,"=");
//        $query->add_where(1,'users_roles.rid','4' ,'=');
//				$query->where['1']['conditions']['1']['field'] = 'field_data_field_tagswithhs.field_tagswithhs_tid';
//				$query->where['1']['conditions']['1']['value'] = array();
//				$query->where['1']['conditions']['1']['value'][] =48;
//				$query->where['1']['conditions']['1']['value'][] =20;
//				kpr($view);
//				kpr($query);
		}
}
*/
		