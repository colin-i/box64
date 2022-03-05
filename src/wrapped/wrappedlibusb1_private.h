#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error meh!
#endif

GOM(libusb_alloc_transfer, pFEi)
GO(libusb_attach_kernel_driver, iFpi)
GO(libusb_bulk_transfer, iFpCpipu)
GOM(libusb_cancel_transfer, iFEp)
GO(libusb_claim_interface, iFpi)
GO(libusb_clear_halt, iFpC)
GO(libusb_close, vFp)
GO(libusb_control_transfer, iFpCCWWpWu)
GO(libusb_detach_kernel_driver, iFpi)
GO(libusb_error_name, pFi)
GO(libusb_event_handler_active, iFp)
GO(libusb_event_handling_ok, iFp)
GO(libusb_exit, vFp)
GO(libusb_free_bos_descriptor, vFp)
GO(libusb_free_config_descriptor, vFp)
GO(libusb_free_container_id_descriptor, vFp)
GO(libusb_free_device_list, vFpi)
GO(libusb_free_ss_endpoint_companion_descriptor, vFp)
GO(libusb_free_ss_usb_device_capability_descriptor, iFppp)
GO(libusb_free_transfer, vFp)
GO(libusb_free_usb_2_0_extension_descriptor, vFp)
GO(libusb_get_active_config_descriptor, iFpp)
GO(libusb_get_bos_descriptor, iFpp)
GO(libusb_get_bus_number, CFp)
GO(libusb_get_config_descriptor, iFpCp)
GO(libusb_get_config_descriptor_by_value, iFpCp)
GO(libusb_get_configuration, iFpp)
GO(libusb_get_container_id_descriptor, iFppp)
GO(libusb_get_device, pFp)
GO(libusb_get_device_address, CFp)
GO(libusb_get_device_descriptor, iFpp)
GO(libusb_get_device_list, lFpp)
GO(libusb_get_device_speed, iFp)
GO(libusb_get_max_iso_packet_size, iFpC)
GO(libusb_get_max_packet_size, iFpC)
GO(libusb_get_next_timeout, iFpp)
GO(libusb_get_parent, pFp)
GO(libusb_get_pollfds, pFp)
GO(libusb_get_port_number, CFp)
GO(libusb_get_port_numbers, iFppi)
GO(libusb_get_port_path, iFpppC)
GO(libusb_get_ss_endpoint_companion_descriptor, iFppp)
GO(libusb_get_ss_usb_device_capability_descriptor, iFppp)
GO(libusb_get_string_descriptor_ascii, iFpCpi)
GO(libusb_get_usb_2_0_extension_descriptor, iFppp)
GO(libusb_get_version, pFv)
GO(libusb_handle_events, iFp)
GO(libusb_handle_events_completed, iFpp)
GO(libusb_handle_events_locked, iFpp)
GO(libusb_handle_events_timeout, iFpp)
GO(libusb_handle_events_timeout_completed, iFppp)
GO(libusb_has_capability, iFu)
GO(libusb_hotplug_deregister_callback, vFpi)
GOM(libusb_hotplug_register_callback, iFEpiiiiippp)
GO(libusb_init, iFp)
GO(libusb_interrupt_transfer, iFpCpipu)
GO(libusb_interrupt_event_handler, iFp) // since 1.0.21 (API_VERSION > 0x01000105)
GO(libusb_kernel_driver_active, iFpi)
GO(libusb_lock_events, vFp)
GO(libusb_lock_event_waiters, vFp)
GO(libusb_open, iFpp)
GO(libusb_open_device_with_vid_pid, pFpWW)
GO(libusb_pollfds_handle_timeouts, iFp)
GO(libusb_ref_device, pFp)
GO(libusb_release_interface, iFpi)
GO(libusb_reset_device, iFp)
GO(libusb_set_auto_detach_kernel_driver, iFpi)
GO(libusb_set_configuration, iFpi)
GO(libusb_set_debug, vFpi)
GO(libusb_set_interface_alt_setting, iFpii)
GO(libusb_setlocale, iFp)
//GOM(libusb_set_pollfd_notifiers, vFpppp)
GO(libusb_strerror, pFi)
GOM(libusb_submit_transfer, iFEp)
GO(libusb_transfer_get_stream_id, uFp)  //v1.0.19+ , no need to wrap callback here
GO(libusb_transfer_set_stream_id, vFpu) //v1.0.19+ , no need to wrap callback here
GO(libusb_try_lock_events, iFp)
GO(libusb_unlock_events, vFp)
GO(libusb_unlock_event_waiters, vFp)
GO(libusb_unref_device, vFp)
GO(libusb_wait_for_event, iFpp)